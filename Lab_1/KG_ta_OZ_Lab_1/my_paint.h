#ifndef MY_PAINT_H
#define MY_PAINT_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class My_Paint : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit My_Paint(QWidget *parent = NULL);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void scene();
};

#endif // MY_PAINT_H
