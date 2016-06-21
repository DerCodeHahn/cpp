/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *action_2;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionRectangle;
    QAction *actionCircle;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *paint;
    QWidget *widget;
    QPushButton *clearButton;
    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *selectedColor;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuFroms;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(630, 358);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        paint = new QWidget(centralWidget);
        paint->setObjectName(QStringLiteral("paint"));

        horizontalLayout->addWidget(paint);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(150, 16777215));
        widget->setAutoFillBackground(true);
        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(10, 0, 75, 23));
        clearButton->setFlat(false);
        redSlider = new QSlider(widget);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setGeometry(QRect(40, 60, 91, 22));
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Horizontal);
        greenSlider = new QSlider(widget);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setGeometry(QRect(40, 90, 91, 20));
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Horizontal);
        blueSlider = new QSlider(widget);
        blueSlider->setObjectName(QStringLiteral("blueSlider"));
        blueSlider->setGeometry(QRect(40, 120, 91, 20));
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 16, 16));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 16, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 16, 16));
        selectedColor = new QFrame(widget);
        selectedColor->setObjectName(QStringLiteral("selectedColor"));
        selectedColor->setGeometry(QRect(10, 30, 121, 21));
        selectedColor->setFrameShape(QFrame::StyledPanel);
        selectedColor->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFroms = new QMenu(menuBar);
        menuFroms->setObjectName(QStringLiteral("menuFroms"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuFroms->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(action_2);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFroms->addAction(actionCircle);
        menuFroms->addAction(actionRectangle);
        mainToolBar->addAction(actionRectangle);
        mainToolBar->addAction(actionCircle);

        retranslateUi(MainWindow);

        clearButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0));
        action_2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionRectangle->setText(QApplication::translate("MainWindow", "Rectangle", 0));
        actionCircle->setText(QApplication::translate("MainWindow", "Circle", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        label->setText(QApplication::translate("MainWindow", "R", 0));
        label_2->setText(QApplication::translate("MainWindow", "G", 0));
        label_3->setText(QApplication::translate("MainWindow", "B", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuFroms->setTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
