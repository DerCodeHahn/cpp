#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "brush.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    class MyLabel*  label_;
    my::Image       image_;
    my::Brush       activeBrush;
public:
    explicit MainWindow(QWidget *parent = 0);
    void UpdateImage();
    QColor activeColor;
    ~MainWindow();
private slots:
    void handleButton();
    void SlideRed(int val);
    void SlideGreen(int val);
    void SlideBlue(int val);
    void ChangeSize(int val);
private:
    Ui::MainWindow *ui;
    void SetSelectedColor();
    uint32_t GetActiveColorCode();
};

#endif // MAINWINDOW_H
