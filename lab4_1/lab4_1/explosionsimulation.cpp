#include "explosionsimulation.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

ExplosionSimulation::ExplosionSimulation(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&timer, &QTimer::timeout, this, &ExplosionSimulation::updateBubbles);
}

void ExplosionSimulation::startAnimation()
{
    initBubbles();
    timer.start(30);
}

void ExplosionSimulation::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 1.0, 1.0); // Синій фон
}

void ExplosionSimulation::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < MAX_BUBBLES; i++) {
        if (bubbles[i].life > 0.0f) {
            glPushMatrix();
            glTranslatef(bubbles[i].x, bubbles[i].y, bubbles[i].z);
            glColor3f(1.0f, 1.0f, 1.0f); // Білий колір бульбашок
            GLUquadric *quadric = gluNewQuadric();
            gluSphere(quadric, bubbles[i].size, 10, 10); // Малюємо сферу
            gluDeleteQuadric(quadric);
            glPopMatrix();
        }
    }
}

void ExplosionSimulation::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void ExplosionSimulation::initBubbles()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAX_BUBBLES; i++) {
        bubbles[i].life = 1.0f; // Тривалість життя
        bubbles[i].size = static_cast<float>(rand() % 5 + 1) * 0.01f; // Різний розмір
        bubbles[i].x = static_cast<float>(rand() % 20 - 10) * 0.1f; // Випадкова позиція X
        bubbles[i].y = static_cast<float>(rand() % 20) * -0.1f; // Випадкова позиція Y
        bubbles[i].z = static_cast<float>(rand() % 20 - 10) * 0.1f; // Випадкова позиція Z
    }
}

void ExplosionSimulation::updateBubbles()
{
    for (int i = 0; i < MAX_BUBBLES; i++) {
        if (bubbles[i].life > 0.0f) {
            bubbles[i].y += 0.01f; // Бульбашки піднімаються
            bubbles[i].life -= 0.01f; // Зменшуємо тривалість життя
        } else {
            // Скидання бульбашки
            bubbles[i].life = 1.0f;
            bubbles[i].x = static_cast<float>(rand() % 20 - 10) * 0.1f;
            bubbles[i].y = -0.1f; // Початкова позиція Y
            bubbles[i].z = static_cast<float>(rand() % 20 - 10) * 0.1f;
        }
    }
    update(); // Оновлення візуалізації
}
