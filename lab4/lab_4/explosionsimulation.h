#ifndef EXPLOSIONSIMULATION_H
#define EXPLOSIONSIMULATION_H

#include <QOpenGLWidget>
#include <QTimer>

struct Particle {
    float life;
    float fade;
    float x, y, z;
    float xi, yi, zi;
    float r, g, b;
};

class ExplosionSimulation : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit ExplosionSimulation(QWidget *parent = NULL);
    void startExplosion();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    static const int MAX_PARTICLES = 1000;
    Particle particles[MAX_PARTICLES];
    QTimer timer;

    void initParticles();
    void updateParticles();
};

#endif // EXPLOSIONSIMULATION_H
