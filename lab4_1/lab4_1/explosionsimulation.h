#ifndef EXPLOSIONSIMULATION_H
#define EXPLOSIONSIMULATION_H

#include <QOpenGLWidget>
#include <QTimer>

struct Bubble {
    float life;   // Тривалість життя бульбашки
    float x, y, z; // Позиція бульбашки
    float size;   // Розмір бульбашки
};

class ExplosionSimulation : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit ExplosionSimulation(QWidget *parent = NULL);
    void startAnimation();  // Метод для запуску анімації

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    static const int MAX_BUBBLES = 100; // Максимальна кількість бульбашок
    Bubble bubbles[MAX_BUBBLES]; // Масив для зберігання бульбашок
    QTimer timer; // Таймер для контролю оновлень

    void initBubbles(); // Метод для ініціалізації бульбашок
    void updateBubbles(); // Метод для оновлення стану бульбашок
};

#endif // EXPLOSIONSIMULATION_H
