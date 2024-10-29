#include "explosionsimulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExplosionSimulation explosionSim;
    explosionSim.show();
    explosionSim.startExplosion();  // Запуск ефекту вибуху

    return a.exec();
}
