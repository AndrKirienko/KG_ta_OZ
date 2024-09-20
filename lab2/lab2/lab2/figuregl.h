#ifndef FIGUREGL_H
#define FIGUREGL_H
#include <QColor>
#include <QtOpenGL>
#include <QGLWidget>

class figureGL : public QGLWidget
{
public:
    figureGL(int r = 0, int g = 0, int b = 0);
    void initializeGL();
    void initializeGL(QColor rgb);
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void scene();
    void timer();
    void mouseMoveEvent(QMouseEvent*me);
    void keyPressEvent(QKeyEvent *event);
};

#endif // FIGUREGL_H
