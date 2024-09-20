#include "mainscene.h"
#include "figuregl.h"
#include <QtOpenGL>
#include <GL/gl.h>

MainScene::MainScene()
{

}

void MainScene::mousePressEvent(QMouseEvent *event)
{
pressPosition = event->pos();
}
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
xAxisRotation +=(180*((GLfloat)event->y()-(GLfloat)pressPosition.y()))/(currentHeight);
yAxisRotation +=(180*((GLfloat)event->x()-(GLfloat)pressPosition.x()))/(currentWidth);
pressPosition = event->pos();
updateGL();
}

GLfloat rc;// Кут повороту літер
figureGL::figureGL(int r, int g, int b)
{
    r = 0;
    g = 0;
    b = 0;
}
void figureGL::initializeGL()
{
//Задаємо колір фону в OpenGL вікні
qglClearColor(Qt::black);
}
void figureGL::initializeGL(QColor rgb)
{
qglClearColor(rgb); // Вибираємо колірну палітру типу RGB
}
void figureGL::resizeGL(int nWidth, int nHeight)
{
// Встановлюємо точку огляду.
glViewport(0, 0, nWidth, nHeight);
// Встановлюємо режим матриці.
glMatrixMode(GL_PROJECTION);
// Завантажуємо матрицю
glLoadIdentity();
glClearDepth (1.0f); // Дозволяємо очищення буфера глибини
glEnable (GL_DEPTH_TEST); //Дозволяємо тест глибини
glDepthFunc (GL_LEQUAL); // Тип тесту глибини
glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
// Поліпшення в обчисленні перспективи
glEnable (GL_BLEND); // Дозволяємо змішування
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// Вказуємо спосіб змішування
}

void figureGL::paintGL()
{
struct MyThread : public QThread {using QThread::msleep;};
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Очистити екран і буфер глибини
// Тут малюємо (для зручності, в окремій функції)
scene();
//выводимо на екран
swapBuffers();
//MyThread::msleep(5000);
}
void figureGL::scene()
{
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Очистити екран і буфер глибини
glLoadIdentity();
glTranslatef(0.0, 0.0,0.0);
glRotatef(rc, 0.0, 1.0, 0.0f); // функція обертання
glBegin(GL_QUADS); // створюємо букву квадратними полігонами
//К – передня частина
qglColor(Qt::red); // заливаємо червоним кольором
glVertex3f(0.1, 0.1, 0.2);//1
glVertex3f(0.1, 0.7, 0.2);//2
glVertex3f(0.2, 0.7, 0.2);//3
glVertex3f(0.2, 0.1, 0.2);//10

glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.4, 0.7, 0.2);//5
glVertex3f(0.5, 0.7, 0.2);//6
glVertex3f(0.3, 0.4, 0.2);//7

glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.4, 0.1, 0.2);//9
glVertex3f(0.5, 0.1, 0.2);//8
glVertex3f(0.3, 0.4, 0.2);//7

//К-задня частина
qglColor(Qt::red);
glVertex3f(0.1, 0.1, 0.3);//1
glVertex3f(0.1, 0.7, 0.3);//2
glVertex3f(0.2, 0.7, 0.3);//3
glVertex3f(0.2, 0.1, 0.3);//10

glVertex3f(0.2, 0.4, 0.3);//4
glVertex3f(0.4, 0.7, 0.3);//5
glVertex3f(0.5, 0.7, 0.3);//6
glVertex3f(0.3, 0.4, 0.3);//7

glVertex3f(0.2, 0.4, 0.3);//4
glVertex3f(0.4, 0.1, 0.3);//9
glVertex3f(0.5, 0.1, 0.3);//8
glVertex3f(0.3, 0.4, 0.3);//7

//K- бокові частини
qglColor(Qt::red);
glVertex3f(0.1, 0.1, 0.2);//1
glVertex3f(0.1, 0.7, 0.2);//2
glVertex3f(0.1, 0.7, 0.3);//2z
glVertex3f(0.1, 0.1, 0.3);//1z

qglColor(Qt::red);
glVertex3f(0.1, 0.7, 0.2);//2
glVertex3f(0.2, 0.7, 0.2);//3
glVertex3f(0.1, 0.7, 0.3);//2z
glVertex3f(0.2, 0.7, 0.3);//3z

qglColor(Qt::red);
glVertex3f(0.2, 0.7, 0.2);//3
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.2, 0.4, 0.3);//4z
glVertex3f(0.2, 0.7, 0.3);//3z

qglColor(Qt::red);
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.4, 0.7, 0.2);//5
glVertex3f(0.4, 0.7, 0.3);//5z
glVertex3f(0.2, 0.4, 0.3);//4z

qglColor(Qt::red);
glVertex3f(0.4, 0.7, 0.2);//5
glVertex3f(0.5, 0.7, 0.2);//6
glVertex3f(0.6, 0.7, 0.3);//6z
glVertex3f(0.4, 0.7, 0.3);//5z

qglColor(Qt::red);
glVertex3f(0.5, 0.7, 0.2);//6
glVertex3f(0.3, 0.4, 0.2);//7
glVertex3f(0.3, 0.4, 0.3);//7z
glVertex3f(0.5, 0.7, 0.2);//6z

qglColor(Qt::red);
glVertex3f(0.3, 0.4, 0.2);//7
glVertex3f(0.5, 0.1, 0.2);//8
glVertex3f(0.5, 0.1, 0.3);//8z
glVertex3f(0.3, 0.4, 0.3);//7z

qglColor(Qt::red);
glVertex3f(0.5, 0.1, 0.2);//8
glVertex3f(0.4, 0.1, 0.2);//9
glVertex3f(0.4, 0.1, 0.3);//9z
glVertex3f(0.5, 0.1, 0.3);//8z

qglColor(Qt::red);
glVertex3f(0.4, 0.1, 0.2);//9
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.2, 0.4, 0.3);//4z
glVertex3f(0.4, 0.1, 0.3);//9z

qglColor(Qt::red);
glVertex3f(0.2, 0.1, 0.2);//10
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.2, 0.4, 0.3);//4z
glVertex3f(0.2, 0.1, 0.3);//10z

qglColor(Qt::red);
glVertex3f(0.1, 0.1, 0.2);//1
glVertex3f(0.2, 0.1, 0.2);//10
glVertex3f(0.2, 0.1, 0.3);//10z
glVertex3f(0.1, 0.1, 0.3);//1z

glEnd();
glLineWidth(2.0); //координати меж літери K
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
//передня частина
glVertex3f(0.1, 0.1, 0.2);//1
glVertex3f(0.1, 0.7, 0.2);//2
glVertex3f(0.2, 0.7, 0.2);//3
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.4, 0.7, 0.2);//5
glVertex3f(0.5, 0.7, 0.2);//6
glVertex3f(0.3, 0.4, 0.2);//7
glVertex3f(0.5, 0.1, 0.2);//8
glVertex3f(0.4, 0.1, 0.2);//9
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.2, 0.1, 0.2);//10
glVertex3f(0.1, 0.1, 0.2);//1

glEnd();
glBegin(GL_LINE_STRIP);
//задня частина
glVertex3f(0.1, 0.1, 0.3);//1z
glVertex3f(0.1, 0.7, 0.3);//2z
glVertex3f(0.2, 0.7, 0.3);//3z
glVertex3f(0.2, 0.4, 0.3);//4z
glVertex3f(0.4, 0.7, 0.3);//5z
glVertex3f(0.5, 0.7, 0.3);//6z
glVertex3f(0.3, 0.4, 0.3);//7z
glVertex3f(0.5, 0.1, 0.3);//8z
glVertex3f(0.4, 0.1, 0.3);//9z
glVertex3f(0.2, 0.4, 0.3);//4z
glVertex3f(0.2, 0.1, 0.3);//10z
glVertex3f(0.1, 0.1, 0.3);//1z
glEnd();
glBegin(GL_LINE_STRIP); // (GL_LINE_STRIP)-лінія з 2х точок
glVertex3f(0.1, 0.1, 0.2); //1
glVertex3f(0.1, 0.1, 0.3); //1z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.1, 0.7, 0.2);//2
glVertex3f(0.1, 0.7, 0.3);//2z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.2, 0.7, 0.2);//3
glVertex3f(0.2, 0.7, 0.3);//3z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.2, 0.4, 0.2);//4
glVertex3f(0.2, 0.4, 0.3);//4z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.4, 0.7, 0.2);//5
glVertex3f(0.4, 0.7, 0.3);//5z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.5, 0.7, 0.2);//6
glVertex3f(0.5, 0.7, 0.3);//6z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.3, 0.4, 0.2);//7
glVertex3f(0.3, 0.4, 0.3);//7z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.5, 0.1, 0.2);//8
glVertex3f(0.5, 0.1, 0.3);//8z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.4, 0.1, 0.2);//9
glVertex3f(0.4, 0.1, 0.3);//9z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.2, 0.1, 0.2);//10
glVertex3f(0.2, 0.1, 0.3);//10z
glEnd();
//О – передня частина
glBegin(GL_QUADS);
qglColor(Qt::red);
glVertex3f(0.7, 0.1, 0.2);// 1
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.7, 0.25, 0.2);//10
glVertex3f(0.75, 0.2, 0.2);//9

qglColor(Qt::red);
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.7, 0.25, 0.2);//10
glVertex3f(0.7, 0.55, 0.2);//11
glVertex3f(0.6, 0.6, 0.2);//3

qglColor(Qt::red);
glVertex3f(0.6, 0.6, 0.2);//3
glVertex3f(0.7, 0.55, 0.2);//11
glVertex3f(0.75, 0.6, 0.2);//12
glVertex3f(0.7, 0.7, 0.2);//4

qglColor(Qt::red);
glVertex3f(0.75, 0.6, 0.2);//12
glVertex3f(0.7, 0.7, 0.2);//4
glVertex3f(0.9, 0.7, 0.2);//5
glVertex3f(0.85, 0.6, 0.2);//13

qglColor(Qt::red);
glVertex3f(0.85, 0.6, 0.2);//13
glVertex3f(0.9, 0.7, 0.2);//5
glVertex3f(1, 0.6, 0.2);//6
glVertex3f(0.9, 0.55, 0.2);//14

qglColor(Qt::red);
glVertex3f(0.9, 0.55, 0.2);//14
glVertex3f(1, 0.6, 0.2);//6
glVertex3f(1, 0.2, 0.2);//7
glVertex3f(0.9, 0.25, 0.2);//15

qglColor(Qt::red);
glVertex3f(0.9, 0.25, 0.2);//15
glVertex3f(1, 0.2, 0.2);//7
glVertex3f(0.9, 0.1, 0.2);//8
glVertex3f(0.85, 0.2, 0.2);//16

qglColor(Qt::red);
glVertex3f(0.9, 0.1, 0.2);//8
glVertex3f(0.85, 0.2, 0.2);//16
glVertex3f(0.75, 0.2, 0.2);//9
glVertex3f(0.7, 0.1, 0.2);//1

//O-задня частина
qglColor(Qt::red);
glVertex3f(0.7, 0.1, 0.3);// 1z
glVertex3f(0.6, 0.2, 0.3);//2z
glVertex3f(0.7, 0.25, 0.3);//10z
glVertex3f(0.75, 0.2, 0.3);//9z

qglColor(Qt::red);
glVertex3f(0.6, 0.2, 0.3);//2z
glVertex3f(0.7, 0.25, 0.3);//10z
glVertex3f(0.7, 0.55, 0.3);//11z
glVertex3f(0.6, 0.6, 0.3);//3z

qglColor(Qt::red);
glVertex3f(0.6, 0.6, 0.3);//3z
glVertex3f(0.7, 0.55, 0.3);//11z
glVertex3f(0.75, 0.6, 0.3);//12z
glVertex3f(0.7, 0.7, 0.3);//4z

qglColor(Qt::red);
glVertex3f(0.75, 0.6, 0.3);//12z
glVertex3f(0.7, 0.7, 0.3);//4z
glVertex3f(0.9, 0.7, 0.3);//5z
glVertex3f(0.85, 0.6, 0.3);//13z

qglColor(Qt::red);
glVertex3f(0.85, 0.6, 0.3);//13z
glVertex3f(0.9, 0.7, 0.3);//5z
glVertex3f(1, 0.6, 0.3);//6z
glVertex3f(0.9, 0.55, 0.3);//14z

qglColor(Qt::red);
glVertex3f(0.9, 0.55, 0.3);//14z
glVertex3f(1, 0.6, 0.3);//6z
glVertex3f(1, 0.2, 0.3);//7z
glVertex3f(0.9, 0.25, 0.3);//15z

qglColor(Qt::red);
glVertex3f(0.9, 0.25, 0.3);//15z
glVertex3f(1, 0.2, 0.3);//7z
glVertex3f(0.9, 0.1, 0.3);//8z
glVertex3f(0.85, 0.2, 0.3);//16z

qglColor(Qt::red);
glVertex3f(0.9, 0.1, 0.3);//8z
glVertex3f(0.85, 0.2, 0.3);//16z
glVertex3f(0.75, 0.2, 0.3);//9z
glVertex3f(0.7, 0.1, 0.3);//1z

//O- бокові частини
glVertex3f(0.7, 0.1, 0.2);// 1
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.6, 0.2, 0.3);//2z
glVertex3f(0.7, 0.1, 0.3);// 1z

glVertex3f(0.6, 0.6, 0.2);//3
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.6, 0.2, 0.3);//2z
glVertex3f(0.6, 0.6, 0.3);//3z

glVertex3f(0.7, 0.7, 0.2);//4
glVertex3f(0.6, 0.6, 0.2);//3
glVertex3f(0.6, 0.6, 0.3);//3z
glVertex3f(0.7, 0.7, 0.3);//4z

glVertex3f(0.9, 0.7, 0.2);//5
glVertex3f(0.7, 0.7, 0.2);//4
glVertex3f(0.7, 0.7, 0.3);//4z
glVertex3f(0.9, 0.7, 0.3);//5z

glVertex3f(0.85, 0.25, 0.2);//11
glVertex3f(0.65, 0.25, 0.2);//8
glVertex3f(0.65, 0.25, 0.3);//8z
glVertex3f(0.85, 0.25, 0.3);//11z
glVertex3f(0.5, 0.1, 0.2);//7
glVertex3f(0.65, 0.25, 0.2);//8
glVertex3f(0.65, 0.25, 0.3);//8z
glVertex3f(0.5, 0.1, 0.3);//7z
glVertex3f(0.5, 0.1, 0.2);// 1
glVertex3f(0.5, 0.1, 0.2);//7
glVertex3f(0.5, 0.1, 0.3);//7z
glVertex3f(0.5, 0.1, 0.3);// 1z
glVertex3f(0.675, 0.35, 0.2);//9
glVertex3f(0.75, 0.55, 0.2);//6
glVertex3f(0.75, 0.55, 0.3);//6z
glVertex3f(0.675, 0.35, 0.3);//9z
glVertex3f(0.75, 0.55, 0.2);//6
glVertex3f(0.825, 0.35, 0.2);//10
glVertex3f(0.825, 0.35, 0.3);//10z
glVertex3f(0.75, 0.55, 0.3);//6z
glVertex3f(0.675, 0.35, 0.2);//9
glVertex3f(0.825, 0.35, 0.2);//10
glVertex3f(0.825, 0.35, 0.3);//10z
glVertex3f(0.675, 0.35, 0.3);//9z
glEnd();

glLineWidth(2.0); //координати меж літери A
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.1, 0.2);// 1
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.6, 0.6, 0.2);//3
glVertex3f(0.7, 0.7, 0.2);//4
glVertex3f(0.9, 0.7, 0.2);//5
glVertex3f(1, 0.6, 0.2);//6
glVertex3f(1, 0.2, 0.2);//7
glVertex3f(0.9, 0.1, 0.2);//8
glVertex3f(0.7, 0.1, 0.2);// 1
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(0.75, 0.2, 0.2);//9
glVertex3f(0.7, 0.25, 0.2);//10
glVertex3f(0.7, 0.55, 0.2);//11
glVertex3f(0.75, 0.6, 0.2);//12
glVertex3f(0.85, 0.6, 0.2);//13
glVertex3f(0.9, 0.55, 0.2);//14
glVertex3f(0.9, 0.25, 0.2);//15
glVertex3f(0.85, 0.2, 0.2);//16
glVertex3f(0.75, 0.2, 0.2);//9

glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.1, 0.3);// 1z
glVertex3f(0.6, 0.2, 0.3);//2z
glVertex3f(0.6, 0.6, 0.3);//3z
glVertex3f(0.7, 0.7, 0.3);//4z
glVertex3f(0.9, 0.7, 0.3);//5z
glVertex3f(1, 0.6, 0.3);//6z
glVertex3f(1, 0.2, 0.3);//7z
glVertex3f(0.9, 0.1, 0.3);//8z
glVertex3f(0.7, 0.1, 0.3);// 1z
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(0.75, 0.2, 0.3);//9z
glVertex3f(0.7, 0.25, 0.3);//10z
glVertex3f(0.7, 0.55, 0.3);//11z
glVertex3f(0.75, 0.6, 0.3);//12z
glVertex3f(0.85, 0.6, 0.3);//13z
glVertex3f(0.9, 0.55, 0.3);//14z
glVertex3f(0.9, 0.25, 0.3);//15z
glVertex3f(0.85, 0.2, 0.3);//16z
glVertex3f(0.75, 0.2, 0.3);//9z

glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.1, 0.2);// 1
glVertex3f(0.7, 0.1, 0.3);// 1z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.6, 0.2, 0.2);//2
glVertex3f(0.6, 0.2, 0.3);//2z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.6, 0.6, 0.2);//3
glVertex3f(0.6, 0.6, 0.3);//3z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.7, 0.2);//4
glVertex3f(0.7, 0.7, 0.3);//4z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.9, 0.7, 0.2);//5
glVertex3f(0.9, 0.7, 0.3);//5z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(1, 0.6, 0.2);//6
glVertex3f(1, 0.6, 0.3);//6z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(1, 0.2, 0.2);//7
glVertex3f(1, 0.2, 0.3);//7z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.9, 0.1, 0.2);//8
glVertex3f(0.9, 0.1, 0.3);//8z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.75, 0.2, 0.2);//9
glVertex3f(0.75, 0.2, 0.3);//9z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.25, 0.2);//10
glVertex3f(0.7, 0.25, 0.3);//10z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.7, 0.55, 0.2);//11
glVertex3f(0.7, 0.55, 0.3);//11z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.75, 0.6, 0.2);//12
glVertex3f(0.75, 0.6, 0.3);//12z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.85, 0.6, 0.2);//13
glVertex3f(0.85, 0.6, 0.3);//13z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.9, 0.55, 0.2);//14
glVertex3f(0.9, 0.55, 0.3);//14z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.9, 0.25, 0.2);//15
glVertex3f(0.9, 0.25, 0.3);//15z
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3f(0.85, 0.2, 0.2);//16
glVertex3f(0.85, 0.2, 0.3);//16z
glEnd();
rc -= 0.15f; // кут і напрямок повороту
}
void figureGL::timer()
{
for (int i=0; i<1; i--)
{ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Очистити екран і буфер глибини
paintGL();
} }
void figureGL::mouseMoveEvent(QMouseEvent*me)
{ timer(); }
void figureGL::keyPressEvent(QKeyEvent *event)
{
timer();
}
