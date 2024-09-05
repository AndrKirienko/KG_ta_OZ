#include "my_paint.h"
#include <GL/gl.h>
#include <cmath>

My_Paint::My_Paint(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void drawCircle(float cx, float cy, float radius, int segments = 36) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Центр кола
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * M_PI * i / segments;
        float x = cx + radius * cosf(angle);
        float y = cy + radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void My_Paint::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 50.0, 50.0, 1.0);
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

    //верхне-нижнє коло
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(110.0, 130.0, 5.0);
    glDisable(GL_LINE_SMOOTH);

    //верхне-верхнє коло
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(60.0, 190.0, 5.0);
    glDisable(GL_LINE_SMOOTH);

    //верхня лінія

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glLineWidth(10.0);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(110.0, 130.0, 0.0);
    glVertex3f(60.0, 190.0, 0.0);
    glEnd();

    //нижнє-нижнє коло
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(50.0, 40.0, 5.0);
    glDisable(GL_LINE_SMOOTH);

    //нижнє-верхнє коло
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(115.0, 70.0, 5.0);
    glDisable(GL_LINE_SMOOTH);

    //нижня лінія
    glLineWidth(10.0);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(115.0, 70.0, 0.0);
    glVertex3f(50.0, 40.0, 0.0);
    glEnd();

    glDisable(GL_LINE_SMOOTH);

    //верхня точка
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPointSize(10.0);
    glColor4f(0.0, 0.0, 0.0, 0.5);

    glBegin(GL_POINTS);
    glVertex3f(150.0, 130.0, 0.0);
    glEnd();

    //нижня точка
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPointSize(10.0);
    glColor4f(0.0, 0.0, 0.0, 0.5);

    glBegin(GL_POINTS);
    glVertex3f(135.0, 85.0, 0.0);
    glEnd();

}
