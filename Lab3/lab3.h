#ifndef LAB3_H
#define LAB3_H

#include <QMainWindow>
#include <QGLWidget>
#include <QImage>

class Lab3 : public QGLWidget {
    Q_OBJECT

public:
    Lab3(QWidget *parent = NULL);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    GLuint loadTexture(const char* filename);  // Загрузка текстуры
    void drawPolygonPrism(int sides);          // Рисование призмы

private:
    float rotationAngle;  // Угол вращения
    QTimer *timer;        // Таймер для обновления сцены

};



#endif // LAB3_H
