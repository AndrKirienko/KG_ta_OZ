/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *drawButton;
    QLabel *label;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(363, 244);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 170, 93, 28));
        drawButton = new QPushButton(centralWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(210, 120, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 241, 16));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 351, 101));
        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 220, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", 0));
        drawButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\274\320\260\320\273\321\216\320\262\320\260\321\202\320\270", 0));
        label->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\264\320\260\320\275\320\275\321\217 \320\264\320\276 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\276\321\227 \321\200\320\276\320\261\320\276\321\202\320\270", 0));
        label_2->setText(QApplication::translate("MainWindow", "	\320\222\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\276\320\262\321\203\321\216\321\207\320\270 \320\277\321\200\320\270\320\274\321\226\321\202\320\270\320\262\320\270 \302\253\321\202\320\276\321\207\320\272\320\260\302\273, \302\253\320\273\321\226\320\275\321\226\321\217\302\273, \n"
" \302\253\321\202\321\200\320\270\320\272\321\203\321\202\320\275\320\270\320\272\302\273, \302\253\321\207\320\276\321\202\320\270\321\200\320\270\320\272\321\203\321\202\320\275\320\270\320\272\302\273 \321\202\320\260 \302\253\320\274\320\275\320\276\320\263\320\276\320\272\321\203\321\202\320\275\320\270\320\272\302\273 \n"
" \320\267\320\276\320\261\321\200\320\260\320\267\320\270\321\202\320\270 \321\204\321\226\320\263\321\203\321\200\321\203\n"
"", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
