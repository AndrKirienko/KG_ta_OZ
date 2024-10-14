#include "lab3.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>
#include <QTimer>

Lab3::Lab3(QWidget *parent) : QGLWidget(parent), rotationAngle(0.0f) {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));  // Обновление через слот
    timer->start(16);  // 60 FPS
}

void Lab3::initializeGL() {
    glClearColor(1, 1, 1, 1);  // Чёрный фон
    glEnable(GL_DEPTH_TEST);               // Включение теста глубины
    glEnable(GL_LIGHTING);                 // Включение освещения
    glEnable(GL_LIGHT0);                    // Включение первого источника света (красный)
    glEnable(GL_LIGHT1);                    // Включение второго источника света (голубой)
    glEnable(GL_LIGHT2);                    // Включение третьего источника света (зелёный)
    glEnable(GL_LIGHT3);
    glEnable(GL_TEXTURE_2D);               // Включение текстур

    // Параметры для красного света (верхний полигон)
    GLfloat redLightPosition[] = { 0, 0, 1, 0 }; // Позиция света
    GLfloat redLightColor[] = { 1, 0, 0, 0.1 };    // Красный

    glLightfv(GL_LIGHT0, GL_POSITION, redLightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, redLightColor); // Дифузный свет

    // Параметры для голубого света (нижний полигон)
    GLfloat greenLightPosition[] = { 0, 0, -4, 0 }; // Позиция света
    GLfloat greenLightColor[] = { 0, 1, 0, 0.1 };    // Зеленый

    glLightfv(GL_LIGHT1, GL_POSITION, greenLightPosition);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, greenLightColor); // Дифузный свет

    // Параметры для зелёного света (боковые грани слева)
    GLfloat yellowLightPosition[] = { 1, 0, 0, 0 }; // Позиция света
    GLfloat yellowLightColor[] = { 1, 1, 0, 0.1 };    // Жёлтый

    glLightfv(GL_LIGHT2, GL_POSITION, yellowLightPosition);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, yellowLightColor); // Дифузный свет

    // Параметры для зелёного света (боковые грани слева)
    GLfloat blueLightPosition[] = { -2, 0, 0, 0 }; // Позиция света
    GLfloat blueLightColor[] = { 0, 0, 1, 0.1 };    // Жёлтый

    glLightfv(GL_LIGHT3, GL_POSITION, blueLightPosition);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, blueLightColor); // Дифузный свет
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
    glTranslatef(0.0f, 0.0f, -5.0f);  // Смещение камеры

    // Применение вращения
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);  // Вращение вокруг оси Y

    // Загрузка и привязка текстуры
    glBindTexture(GL_TEXTURE_2D, loadTexture("resources/texture.jpg"));

    // Рисование призмы с 9 углами
    drawPolygonPrism(9);


    // Обновление угла вращения для следующего кадра
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f) {
        rotationAngle = 0.0f;  // Сброс угла при полном обороте
    }
}

GLuint Lab3::loadTexture(const char* filename) {
    QImage img(":/resources/texture.jpg");  // Используем путь из ресурсов
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

    // Рисование верхнего полигона
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(x, y);
        glVertex3f(x, y, height / 2);
    }
    glEnd();

    // Рисование нижнего полигона
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(x, y);
        glVertex3f(x, y, -height / 2);
    }
    glEnd();

    // Боковые грани
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
