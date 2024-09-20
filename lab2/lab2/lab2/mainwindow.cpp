#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <figuregl.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
figureGL *opengl_window = new figureGL;
opengl_window->show();
}
