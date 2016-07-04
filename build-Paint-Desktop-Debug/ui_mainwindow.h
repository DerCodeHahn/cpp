/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *actionDot;
    QAction *actionLine;
    QAction *actionRectangle_2;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *paint;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *ColorTab;
    QSpinBox *sizeBox;
    QPushButton *clearButton;
    QCheckBox *RainbowBox;
    QLabel *label_2;
    QSlider *blueSlider;
    QSlider *greenSlider;
    QFrame *selectedColor;
    QLabel *label;
    QSlider *redSlider;
    QLabel *label_3;
    QWidget *historyTab;
    QWidget *tab;
    QPushButton *GameOfLifeBtn;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuFroms;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(669, 355);
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
        actionDot = new QAction(MainWindow);
        actionDot->setObjectName(QStringLiteral("actionDot"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QStringLiteral("actionLine"));
        actionRectangle_2 = new QAction(MainWindow);
        actionRectangle_2->setObjectName(QStringLiteral("actionRectangle_2"));
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
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 161, 281));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        ColorTab = new QWidget();
        ColorTab->setObjectName(QStringLiteral("ColorTab"));
        sizeBox = new QSpinBox(ColorTab);
        sizeBox->setObjectName(QStringLiteral("sizeBox"));
        sizeBox->setGeometry(QRect(90, 30, 42, 22));
        sizeBox->setValue(1);
        clearButton = new QPushButton(ColorTab);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(0, 0, 75, 23));
        clearButton->setDefault(false);
        clearButton->setFlat(false);
        RainbowBox = new QCheckBox(ColorTab);
        RainbowBox->setObjectName(QStringLiteral("RainbowBox"));
        RainbowBox->setEnabled(true);
        RainbowBox->setGeometry(QRect(20, 150, 101, 17));
        RainbowBox->setCheckable(true);
        RainbowBox->setAutoRepeat(false);
        RainbowBox->setTristate(false);
        label_2 = new QLabel(ColorTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 16, 16));
        blueSlider = new QSlider(ColorTab);
        blueSlider->setObjectName(QStringLiteral("blueSlider"));
        blueSlider->setGeometry(QRect(30, 120, 91, 20));
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Horizontal);
        greenSlider = new QSlider(ColorTab);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setGeometry(QRect(30, 90, 91, 20));
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Horizontal);
        selectedColor = new QFrame(ColorTab);
        selectedColor->setObjectName(QStringLiteral("selectedColor"));
        selectedColor->setGeometry(QRect(0, 30, 91, 21));
        selectedColor->setFrameShape(QFrame::StyledPanel);
        selectedColor->setFrameShadow(QFrame::Raised);
        label = new QLabel(ColorTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 16, 16));
        redSlider = new QSlider(ColorTab);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setGeometry(QRect(30, 60, 91, 22));
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(ColorTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 16, 16));
        tabWidget->addTab(ColorTab, QString());
        historyTab = new QWidget();
        historyTab->setObjectName(QStringLiteral("historyTab"));
        tabWidget->addTab(historyTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        GameOfLifeBtn = new QPushButton(tab);
        GameOfLifeBtn->setObjectName(QStringLiteral("GameOfLifeBtn"));
        GameOfLifeBtn->setGeometry(QRect(30, 50, 75, 23));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 10, 101, 17));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 30, 111, 17));
        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 669, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFroms = new QMenu(menuBar);
        menuFroms->setObjectName(QStringLiteral("menuFroms"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        menuFroms->addAction(actionDot);
        menuFroms->addAction(actionLine);
        menuFroms->addAction(actionRectangle_2);
        mainToolBar->addAction(actionRectangle);
        mainToolBar->addAction(actionCircle);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0));
        action_2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionRectangle->setText(QApplication::translate("MainWindow", "Line", 0));
        actionCircle->setText(QApplication::translate("MainWindow", "Dot", 0));
        actionDot->setText(QApplication::translate("MainWindow", "Dot", 0));
        actionDot->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+D", 0));
        actionLine->setText(QApplication::translate("MainWindow", "Line", 0));
        actionLine->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", 0));
        actionRectangle_2->setText(QApplication::translate("MainWindow", "Rectangle", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        RainbowBox->setText(QApplication::translate("MainWindow", "Rainbow Mode", 0));
        label_2->setText(QApplication::translate("MainWindow", "G", 0));
        label->setText(QApplication::translate("MainWindow", "R", 0));
        label_3->setText(QApplication::translate("MainWindow", "B", 0));
        tabWidget->setTabText(tabWidget->indexOf(ColorTab), QApplication::translate("MainWindow", "Color", 0));
        tabWidget->setTabText(tabWidget->indexOf(historyTab), QApplication::translate("MainWindow", "History", 0));
        GameOfLifeBtn->setText(QApplication::translate("MainWindow", "Game of Life", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Single Life Form", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Multiple Life Forms", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Fun", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuFroms->setTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
