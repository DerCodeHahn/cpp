#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "brush.h"
#include "linebrush.h"
#include "rectanglebrush.h"
#include "circlebrush.h"
#include "colorfader.h"
#include "gameoflife.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    class MyLabel*  label_;
    my::Image       image_;
    my::Brush*      activeBrush;
public:
    explicit MainWindow(QWidget *parent = 0);
    void UpdateImage();
    QColor activeColor;
    ~MainWindow();
private slots:
    void ChangeSize(int val);

    void on_actionDot_triggered();

private:
    void handleButton();
    void SetBrushDot();
    void SetBrushLine();
    void SetBrushRectangle();
    void SetBrushCircle();
    void SlideRed(int val);
    void SlideGreen(int val);
    void SlideBlue(int val);
    void ToggleRainbowMode(bool checked);
    void UpdateRainbow();
    void StartGameOfLife();
    void UpdateGameOfLife();
    Ui::MainWindow *ui;
    my::GameOfLife game;
    QTimer *rainbowTimer;
    QTimer *gameOfLifeTimer;
    my::ColorFader colorfader;
    void SetSelectedColor();
    uint32_t GetActiveColorCode();
};

#endif // MAINWINDOW_H
