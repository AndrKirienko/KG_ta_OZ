#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGLWidget>

class MainScene : public QGLWidget
{
Q_OBJECT
public:
    MainScene();
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
QPoint pressPosition;
QPoint releasePosition;
GLfloat xAxisRotation;
GLfloat yAxisRotation;
GLfloat zAxisRotation;
GLfloat currentWidth;
GLfloat currentHeight;
};
#endif // MAINSCENE_H
