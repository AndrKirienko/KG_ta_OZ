#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_paint.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPaintWidget = new My_Paint(this);
        setCentralWidget(myPaintWidget);
        connect(ui->drawButton, &QPushButton::clicked, this, &MainWindow::on_drawButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawButton_clicked()
{
    My_Paint *opengl_window = new My_Paint;
    opengl_window->show();
}
