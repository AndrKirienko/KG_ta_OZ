#include "explosionsimulation.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Конструктор класу ExplosionSimulation
ExplosionSimulation::ExplosionSimulation(QWidget *parent)
    : QOpenGLWidget(parent) // Виклик конструктора базового класу
{
    // Підключення таймера до методу оновлення частинок
    connect(&timer, &QTimer::timeout, this, &ExplosionSimulation::updateParticles);
}

// Метод для запуску симуляції вибуху
void ExplosionSimulation::startExplosion()
{
    initParticles(); // Ініціалізація частинок
    timer.start(30);  // Оновлення кожні 30 мс
}

// Метод для ініціалізації OpenGL
void ExplosionSimulation::initializeGL()
{
    glEnable(GL_DEPTH_TEST); // Включення тесту глибини
    glClearColor(1.0, 1.0, 1.0, 1.0); // Встановлення кольору фону (чорний)
}

// Метод для малювання сцени OpenGL
void ExplosionSimulation::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищення буферів
    glLoadIdentity(); // Скидання матриці

    // Малювання кожної частинки
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].life > 0.0f) { // Перевірка, чи частинка активна
            glColor3f(particles[i].r, particles[i].g, particles[i].b); // Встановлення кольору частинки
            glBegin(GL_TRIANGLE_STRIP); // Початок малювання трикутників
            glVertex3f(particles[i].x + 0.01f, particles[i].y + 0.01f, particles[i].z); // Верхній правий кут
            glVertex3f(particles[i].x - 0.01f, particles[i].y + 0.01f, particles[i].z); // Верхній лівий кут
            glVertex3f(particles[i].x + 0.01f, particles[i].y - 0.01f, particles[i].z); // Нижній правий кут
            glVertex3f(particles[i].x - 0.01f, particles[i].y - 0.01f, particles[i].z); // Нижній лівий кут
            glEnd(); // Завершення малювання
        }
    }
}

// Метод для зміни розміру віджета
void ExplosionSimulation::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // Встановлення вікна перегляду
    glMatrixMode(GL_PROJECTION); // Перехід до проекційної матриці
    glLoadIdentity(); // Скидання матриці
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0); // Встановлення перспективи
    glMatrixMode(GL_MODELVIEW); // Повернення до матриці моделювання
}

// Метод для ініціалізації властивостей частинок
void ExplosionSimulation::initParticles()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].life = 1.0f; // Встановлення початкової тривалості життя частинки
        particles[i].fade = (rand() % 100) / 1000.0f + 0.003f; // Визначення швидкості згасання
        particles[i].x = particles[i].y = particles[i].z = 0.0f; // Початкова позиція
        // Визначення початкових швидкостей частинок
        particles[i].xi = (float)((rand() % 50) - 26.0f) * 0.02f;
        particles[i].yi = (float)((rand() % 50) - 25.0f) * 0.02f;
        particles[i].zi = (float)((rand() % 50) - 25.0f) * 0.02f;
        particles[i].r = 1.0f; // Червоний колір
        particles[i].g = (float)(rand() % 100) / 100.0f; // Випадковий зелений колір
        particles[i].b = 0.0f; // Синій колір
    }
}

// Метод для оновлення стану частинок
void ExplosionSimulation::updateParticles()
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].life > 0.0f) { // Перевірка, чи частинка активна
            // Оновлення позиції частинки
            particles[i].x += particles[i].xi;
            particles[i].y += particles[i].yi;
            particles[i].z += particles[i].zi;
            particles[i].yi -= 0.0008f;  // Гравітація (вплив на Y-вісь)
            particles[i].life -= particles[i].fade; // Зменшення тривалості життя
        } else {
            // Скидання частинки, якщо вона "мертва"
            particles[i].life = 1.0f; // Встановлення нової тривалості життя
            particles[i].x = particles[i].y = particles[i].z = 0.0f; // Встановлення початкової позиції
            // Визначення нових початкових швидкостей
            particles[i].xi = (float)((rand() % 50) - 26.0f) * 0.02f;
            particles[i].yi = (float)((rand() % 50) - 25.0f) * 0.02f;
            particles[i].zi = (float)((rand() % 50) - 25.0f) * 0.02f;
        }
    }
    update(); // Оновлення візуалізації
}
