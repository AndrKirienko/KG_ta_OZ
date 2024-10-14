#ifndef LAB3_H
#define LAB3_H

#include <QMainWindow>

namespace Ui {
class lab3;
}

class lab3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lab3(QWidget *parent = 0);
    ~lab3();

private:
    Ui::lab3 *ui;
};

#endif // LAB3_H
