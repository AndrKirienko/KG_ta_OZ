#include "explosionsimulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExplosionSimulation explosionSim;
    explosionSim.show();
    explosionSim.startAnimation();  // Запуск анімації бульбашок

    return a.exec();
}
