
#include "render_area.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QRectF>
#include <iostream>
#include<QColor>
#include <ctime>


render_area::render_area(QWidget *parent)
    :QWidget(parent),
      damping(0.0f),
      bounce_coeff(1.0f),
      bounce_number(nullptr),
      circ({350,150},5),
      speed(1.0f,-50.0f),
      dt(1/5.0f),
      stored_motion(),
      stored_time(),
      click_previous(),
      is_sphere_selected(false),
      draw_circle(true),
      timer(),
      time(),
      targets(80,4),
      palet(325,275,100,25,10,10)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    //timer calling the function update_timer periodicaly
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    timer.start(30); //every 30ms
    std::srand(std::time(0));
}

render_area::~render_area()
{}



void render_area::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setWidth(1.0);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    QBrush brush = painter.brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    if(draw_circle)
    {
        //the actual drawing of the circle
        vec2 const& p=circ.center;
        float const r=circ.radius;
        painter.drawEllipse(p.x-r,p.y-r,2*r,2*r);
    }
    auto itsup=targets.briques.begin();
    int modif=0;
    for(auto it=targets.briques.begin();it!=targets.briques.end() ;it++){

        bloc temp =*it;
        try{
            brush.setColor(temp.couleur);
            painter.setBrush(brush);
            painter.drawRect(temp.rectangle);
            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if (temp.estToucher(circ)){
                itsup=it;
                modif=1;
            }
        }
        catch(std::exception const& e)
        {
            std::cout<<"erreur lors dessin du rectangle"<<std::endl;
        }

}

    if(modif==1){
        targets.briques.erase(itsup);
        if(norm(speed)<55)
            speed*=-1.000;
        else
            speed*=-1;
        modif=0;
    }
    painter.drawRect(palet.rectangle);
    //if(palet.rectangle.contains({circ.getCoord().x,circ.getCoord().y})){
    if(palet.estToucher(circ)){
        if(norm(speed)<55)
            speed.y*=-1.000;
        else
            speed.y*=-1.0;
        int millieu=(palet.haut_gauche.x()+palet.L/2);
        if(circ.center.x<millieu)
            speed.x-=5;
        else
            speed.x+=5;
//        std::cout<<"la position est "<<position<<std::endl;
//        speed.x+=(position/10);
    }


}




void render_area::mousePressEvent(QMouseEvent *event)
{
    vec2 const click=vec2(event->x(),event->y());

    //check if the click is inside the circle
    if( point_inside_circle(click,circ) )
    {
        //clear the previous data to store new ones
        is_sphere_selected=true;
        stored_motion.clear();
        stored_time.clear();
        click_previous=click;
    }

}





void render_area::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(1);
    if(event->x()>48&&event->x()<708){
        vec2 nouvelle_position(event->x(),275);
//        palet.rectangle.moveCenter({event->x(),288});
        palet.change_haut_gauche(nouvelle_position);
        repaint();
    }
}

void render_area::store_values(vec2 const& click)
{
    //store at most the 5 last position and time of the circle
    stored_motion.push_back(click);
    if(stored_motion.size()>5)
        stored_motion.pop_front();

    stored_time.push_back(time.elapsed());
    if(stored_time.size()>5)
        stored_time.pop_front();
}

void render_area::mouseReleaseEvent(QMouseEvent *event)
{
    //if the sphere was selected
    //  a new speed if computed
    //  the sphere is marked as released

    if(is_sphere_selected)
    {
        vec2 const click=vec2(event->x(),event->y());
        float const t=time.elapsed();

        //compute average speed of the last mouse motion
        float const time_motion=(t-*stored_time.cbegin())/1000.0f;
        vec2 const displacement=click-*stored_motion.cbegin();

        speed=displacement/time_motion*0.05f; //the new speed


        is_sphere_selected=false;
    }
}


void render_area::update_timer()
{
    //called periodically
    if(is_sphere_selected==false) //only integrate when the circle is not selected
        numerical_integration();

    repaint();
}

void render_area::numerical_integration()
{
    //numerical integration using Forward Euler method
    vec2 const gravity={0.0f,0.0f};
    vec2& p=circ.center;

    speed=speed+dt*gravity;  //integrate speed
    speed-=dt*damping*speed; //apply damping
    p = p+dt*speed;          //integrate position

    //collision handling (set new position, and return a new speed value)
    speed=collision_handling(p);
}

vec2 render_area::collision_handling(vec2& p)
{
    vec2 new_speed=speed;

    //size of the window
    float const h=height();
    float const w=width();

    //radius of the sphere
    float const r=circ.radius;

    //special condition in cases of collision
    bool collision=false;
    bool collision_wall=false;
    bool game_over=false;

    //collision with the ground
    if(p.y+r>h)
    {
        p.y=h-r;
        new_speed.y = 0;
        new_speed.x=0;
        collision=true;
        game_over=true;
    }
    //collision with the left wall
    if(p.x-r<0)
    {
        p.x=r;
        new_speed.x *= -1.00;
        collision=true;
        collision_wall=true;
    }
    //collision with the right wall
    if(p.x+r>w)
    {
        p.x=w-r;
        new_speed.x *= -1.00;
        collision=true;
        collision_wall=true;
    }
    //collision with the top wall
    if(p.y-r<0)
    {
        p.y=r;
        new_speed.y *= -1.00;
        collision=true;
        collision_wall=true;
    }

    //decrease speed with respect to the bouncing coefficient
 if(collision)
        new_speed *= bounce_coeff;

    if(game_over==true)
    {
        //increase the information of the number of bounces
        int bounce_nbr=bounce_number->text().toInt();
        draw_circle=false;
        bounce_number->setText("Game Over");
        circ.center.x=0;
        circ.center.y=100;
    }


    return new_speed;

}


void render_area::change_draw_circle_state()
{
    draw_circle=!draw_circle;
}

void render_area::set_damping(float const damping_value)
{
    damping=damping_value;
}
void render_area::set_bounce_coeff(float const bounce_coeff_value)
{
    bounce_coeff=bounce_coeff_value;
}
void render_area::setup_bounce_number(QLabel* bounce_number_value)
{
    bounce_number=bounce_number_value;
}
