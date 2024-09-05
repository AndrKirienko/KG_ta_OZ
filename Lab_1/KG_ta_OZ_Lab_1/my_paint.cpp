#include "my_paint.h"

My_Paint::My_Paint(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void My_Paint::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 128.0, 128.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void My_Paint::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void My_Paint::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width(), 0.0, height(), -1.0, 1.0);
    scene();
}

void My_Paint::scene()
{
    //зелений многокутник
    glColor3f(0.0, 255.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(180.0, 190.0, 0.0);
    glVertex3f(310.0, 130.0, 0.0);
    glVertex3f(230.0, 90.0, 0.0);
    glVertex3f(255.0, 25.0, 0.0);
    glVertex3f(135.0, 15.0, 0.0);
    glEnd();

    //жовтий трикутник
    glColor3f(255.0, 255.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(245.0, 85.0, 0.0);
    glVertex3f(290.0, 100.0, 0.0);
    glVertex3f(265.0, 45.0, 0.0);
    glEnd();

    //центральна лінія
    glLineWidth(3.0);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(230.0, 90.0, 0.0);
    glEnd();

    //верхня лінія
    glLineWidth(10.0);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(110.0, 130.0, 0.0);
    glVertex3f(60.0, 190.0, 0.0);
    glEnd();

    //верхня лінія
    glLineWidth(10.0);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(115.0, 70.0, 0.0);
    glVertex3f(50.0, 40.0, 0.0);
    glEnd();

}
