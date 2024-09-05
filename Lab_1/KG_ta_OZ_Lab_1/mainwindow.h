#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_paint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void on_drawButton_clicked();

private:
    Ui::MainWindow *ui;
    My_Paint *myPaintWidget;
};

#endif // MAINWINDOW_H
