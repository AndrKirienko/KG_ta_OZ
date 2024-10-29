#include "explosionsimulation.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

ExplosionSimulation::ExplosionSimulation(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&timer, &QTimer::timeout, this, &ExplosionSimulation::updateParticles);
}

void ExplosionSimulation::startExplosion()
{
    initParticles();
    timer.start(30);  // Оновлення кожні 30 мс
}

void ExplosionSimulation::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void ExplosionSimulation::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].life > 0.0f) {
            glColor3f(particles[i].r, particles[i].g, particles[i].b);
            glBegin(GL_TRIANGLE_STRIP);
            glVertex3f(particles[i].x + 0.01f, particles[i].y + 0.01f, particles[i].z);
            glVertex3f(particles[i].x - 0.01f, particles[i].y + 0.01f, particles[i].z);
            glVertex3f(particles[i].x + 0.01f, particles[i].y - 0.01f, particles[i].z);
            glVertex3f(particles[i].x - 0.01f, particles[i].y - 0.01f, particles[i].z);
            glEnd();
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

void ExplosionSimulation::initParticles()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].life = 1.0f;
        particles[i].fade = (rand() % 100) / 1000.0f + 0.003f;
        particles[i].x = particles[i].y = particles[i].z = 0.0f;
        particles[i].xi = (float)((rand() % 50) - 26.0f) * 0.02f;
        particles[i].yi = (float)((rand() % 50) - 25.0f) * 0.02f;
        particles[i].zi = (float)((rand() % 50) - 25.0f) * 0.02f;
        particles[i].r = 1.0f;
        particles[i].g = (float)(rand() % 100) / 100.0f;
        particles[i].b = 0.0f;
    }
}

void ExplosionSimulation::updateParticles()
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].life > 0.0f) {
            particles[i].x += particles[i].xi;
            particles[i].y += particles[i].yi;
            particles[i].z += particles[i].zi;
            particles[i].yi -= 0.0008f;  // гравітація
            particles[i].life -= particles[i].fade;
        } else {
            particles[i].life = 1.0f;
            particles[i].x = particles[i].y = particles[i].z = 0.0f;
            particles[i].xi = (float)((rand() % 50) - 26.0f) * 0.02f;
            particles[i].yi = (float)((rand() % 50) - 25.0f) * 0.02f;
            particles[i].zi = (float)((rand() % 50) - 25.0f) * 0.02f;
        }
    }
    update();
}
