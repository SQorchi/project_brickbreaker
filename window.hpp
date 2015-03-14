
#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

//forward declaration
namespace Ui{
class MainWindow;
}
class render_area;

/** Declaration of the window class */
class window: public QMainWindow
{
    Q_OBJECT

public:

    window(QWidget *parent=nullptr);
    ~window();

private slots:

    void action_quit();
    void action_draw();

    /** Called when the damping slider is moved */
    void action_damping_slider(int value);
    /** Called when the boucning coefficient slider is moved */
    void action_bounce_coeff_slider(int value);

private:

    Ui::MainWindow *ui;
    render_area *render;

};

#endif
