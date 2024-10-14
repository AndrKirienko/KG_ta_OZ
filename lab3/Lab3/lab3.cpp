#include "lab3.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>
#include <QTimer>

Lab3::Lab3(QWidget *parent) : QGLWidget(parent), rotationAngle(0.0f) {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(16);  // 60 FPS
}

void Lab3::initializeGL() {
    glClearColor(1, 1, 1, 1);  // фон
    glEnable(GL_DEPTH_TEST);               // Включення тесту глибини
    glEnable(GL_LIGHTING);                 // Включення освітлення
    glEnable(GL_LIGHT0);                    // Включення першого джерела світла (червоний)
    glEnable(GL_LIGHT1);                    // Включення другого джерела світла (блакитний)
    glEnable(GL_LIGHT2);                    // Включення третього джерела світла (зелений)
    glEnable(GL_LIGHT3);                    // Включення четвертого джерела світла
    glEnable(GL_TEXTURE_2D);               // Включення текстур

    // Параметри для червоного світла (верхній полігон)
    GLfloat redLightPosition[] = { 0, 0, 1, 0 }; // Позиція світла
    GLfloat redLightColor[] = { 1, 0, 0, 0.1 };    // Червоний

    glLightfv(GL_LIGHT0, GL_POSITION, redLightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, redLightColor); // Дифузне світло

    // Параметри для блакитного світла (нижній полігон)
    GLfloat greenLightPosition[] = { 0, 0, -4, 0 }; // Позиція світла
    GLfloat greenLightColor[] = { 0, 1, 0, 0.1 };    // Зелений

    glLightfv(GL_LIGHT1, GL_POSITION, greenLightPosition);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, greenLightColor); // Дифузне світло

    // Параметри для жовтого світла (бокові грані зліва)
    GLfloat yellowLightPosition[] = { 1, 0, 0, 0 }; // Позиція світла
    GLfloat yellowLightColor[] = { 1, 1, 0, 0.1 };    // Жовтий

    glLightfv(GL_LIGHT2, GL_POSITION, yellowLightPosition);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, yellowLightColor); // Дифузне світло

    // Параметри для синього світла (бокові грані справа)
    GLfloat blueLightPosition[] = { -2, 0, 0, 0 }; // Позиція світла
    GLfloat blueLightColor[] = { 0, 0, 1, 0.1 };    // Синій

    glLightfv(GL_LIGHT3, GL_POSITION, blueLightPosition);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, blueLightColor); // Дифузне світло
}

void Lab3::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Lab3::paintGL() {
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);  // Зміщення камери

    // Застосування обертання
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);  // Обертання навколо осі Y

    // Завантаження та прив'язка текстури
    glBindTexture(GL_TEXTURE_2D, loadTexture("resources/texture.jpg"));

    // Малювання призми з 9 кутами
    drawPolygonPrism(9);

    // Оновлення кута обертання для наступного кадру
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f) {
        rotationAngle = 0.0f;  // Скидання кута при повному оберті
    }
}

GLuint Lab3::loadTexture(const char* filename) {
    QImage img(":/resources/texture.jpg");  // Використовуємо шлях з ресурсів
    img = QGLWidget::convertToGLFormat(img);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, img.width(), img.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return texture;
}

void Lab3::drawPolygonPrism(int sides) {
    float angleStep = 2.0f * 3.14 / sides;
    float radius = 1.0f;
    float height = 2.0f;

    // Малювання верхнього полігону
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(x, y);
        glVertex3f(x, y, height / 2);
    }
    glEnd();

    // Малювання нижнього полігону
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(x, y);
        glVertex3f(x, y, -height / 2);
    }
    glEnd();

    // Бокові грані
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= sides; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(x, y);
        glVertex3f(x, y, height / 2);
        glTexCoord2f(x, y);
        glVertex3f(x, y, -height / 2);
    }
    glEnd();
}
