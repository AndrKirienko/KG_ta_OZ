#include "lab3.h"
#include "ui_lab3.h"

lab3::lab3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lab3)
{
    ui->setupUi(this);
}

lab3::~lab3()
{
    delete ui;
}
