#ifndef EXPLOSIONSIMULATION_H
#define EXPLOSIONSIMULATION_H

#include <QOpenGLWidget> // Підключення OpenGL віджета для рендерингу
#include <QTimer> // Підключення таймера для періодичних оновлень

// Структура для представлення окремої частинки в вибуху
struct Particle {
    float life;   // Тривалість життя частинки
    float fade;   // Швидкість згасання частинки
    float x, y, z; // Поточна позиція частинки в 3D-просторі
    float xi, yi, zi; // Компоненти початкової швидкості частинки
    float r, g, b; // Колірні компоненти частинки (RGB)
};

// Клас для управління симуляцією вибуху
class ExplosionSimulation : public QOpenGLWidget
{
    Q_OBJECT // Макрос для системи мета-об'єктів Qt

public:
    // Конструктор: ініціалізує віджет і його батька
    explicit ExplosionSimulation(QWidget *parent = NULL);

    // Метод для запуску симуляції вибуху
    void startExplosion();

protected:
    // Функція ініціалізації OpenGL
    void initializeGL() override;

    // Функція для малювання сцени OpenGL
    void paintGL() override;

    // Функція для обробки зміни розміру віджета
    void resizeGL(int w, int h) override;

private:
    static const int MAX_PARTICLES = 1000; // Максимальна кількість частинок
    Particle particles[MAX_PARTICLES]; // Масив для зберігання частинок
    QTimer timer; // Таймер для контролю оновлень частинок

    // Метод для ініціалізації властивостей частинок
    void initParticles();

    // Метод для оновлення стану частинок
    void updateParticles();
};

#endif // EXPLOSIONSIMULATION_H
