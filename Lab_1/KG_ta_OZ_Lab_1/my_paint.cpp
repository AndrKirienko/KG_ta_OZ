#include "my_paint.h"

My_Paint::My_Paint(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void My_Paint::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 0.84, 0.0, 1.0);
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
    glColor3f(1.0, 0.0, 0.0); // Червоний колір

    glBegin(GL_POLYGON);
    glVertex3f(50.0, 350.0, 0.0);
    glVertex3f(250.0, 350.0, 0.0);
    glVertex3f(250.0, 150.0, 0.0);
    glVertex3f(50.0, 150.0, 0.0);
    glEnd();

    // Інші елементи сцени

    //Стрілка вгору
    glColor3f(0.0,0.75,1.0); //Обираємо голубий колір
    glBegin(GL_POLYGON);
    glVertex3f(400.0,275.0,0.0); //Координати трикутника
    glVertex3f(475.0,375.0,0.0);
    glVertex3f(550.0,275.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(435.0,275.0,0.0); //Координати квадрата
    glVertex3f(515.0,275.0,0.0);
    glVertex3f(515.0,175.0,0.0);
    glVertex3f(435.0,175.0,0.0);
    glEnd();
    //Стрілка ліворуч
    glColor3f(0.0,0.75,1.0); //Обираємо голубий колір
    glBegin(GL_POLYGON);
    glVertex3f(350.0,25.0,0.0); //Координати трикутника
    glVertex3f(250.0,100.0,0.0);
    glVertex3f(350.0,175.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(350.0,140.0,0.0); //Координати квадрата
    glVertex3f(525.0,140.0,0.0);
    glVertex3f(525.0,70.0,0.0);
    glVertex3f(350.0,70.0,0.0);
    glEnd();
}
