
#include "window.hpp"

#include "render_area.hpp"
#include "ui_mainwindow.h"

#include <iostream>

window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area)
{
    ui->setupUi(this);
    ui->layout_scene->addWidget(render);
    render->setup_bounce_number(ui->bounces_number);

    //Connection with signals
    connect(ui->quit,SIGNAL(clicked()),this,SLOT(action_quit()));
    connect(ui->draw,SIGNAL(clicked()),this,SLOT(action_draw()));
    connect(ui->damping_slider,SIGNAL(sliderMoved(int)),this,SLOT(action_damping_slider(int)));
    connect(ui->bounce_coeff_slider,SIGNAL(sliderMoved(int)),this,SLOT(action_bounce_coeff_slider(int)));

}


window::~window()
{}

void window::action_quit()
{
    close();
}

void window::action_draw()
{
    render->change_draw_circle_state();
}

void window::action_damping_slider(int const value)
{
    //set the value relative to the current position of the slider

    int maximum=ui->damping_slider->maximum();
    int minimum=ui->damping_slider->minimum();

    //relative value (between [0,1])
    float alpha=static_cast<float>(value-minimum)/(maximum-minimum);

    //damping varies between 0 and 0.2
    float damping=0.2*alpha;

    //draw the new value (in text) of the damping in the label
    std::string str="damping : "+QString::number(damping,'f',2).toStdString();
    ui->label_damping->setText(str.c_str());

    //set the value for the render_area
    render->set_damping(damping);
}

void window::action_bounce_coeff_slider(int const value)
{
    //set the value relative to the current position of the slider

    int maximum=ui->bounce_coeff_slider->maximum();
    int minimum=ui->bounce_coeff_slider->minimum();

    //relative value (between [0,1])
    float alpha=static_cast<float>(value-minimum)/(maximum-minimum);

    //bounding coeff varies between 0 and 1
    float bounce_coeff=alpha;

    //draw the new value (in text) of the bouncing coefficient in the label
    std::string str="bounce coeff : "+QString::number(bounce_coeff,'f',2).toStdString();
    ui->label_coeff->setText(str.c_str());

    //set the value for the render_area
    render->set_bounce_coeff(bounce_coeff);
}
