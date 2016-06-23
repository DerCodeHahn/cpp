#include "mainwindow.h"
#include "mylabel.h"
#include "ui_mainwindow.h"
#include "brush.h"

#include <QPixmap>

#include <iostream>

#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , label_       { new MyLabel(this) }
    , image_       { 800, 400 }
    , activeBrush { new my::Brush() }// = my::Brush(&image_,1);
{
    ui->setupUi(this);

    activeBrush = new my::Brush(&image_,1);
    activeColor = QColor(0,0,0,255);
    //activeBrush = my::Brush(&image_, 3);
    auto update_label = [this]
    {
       auto qimage = QImage(
          reinterpret_cast<uchar const*>(image_.data()), image_.width(), image_.height(),
          sizeof(my::Image::rgba_t)*image_.width(), QImage::Format_ARGB32
       );

       label_->setPixmap(QPixmap::fromImage( qimage ));
    };

    connect( label_, &MyLabel::onMouseMove, [update_label,this](int x, int y)
    {
       std::cout << "mouse move: " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       //image_.set_pixel( x, y, color );
       (*activeBrush).OnMouseMove(x, y, color);
       update_label();
    });

    connect( label_, &MyLabel::onMouseDown, [update_label,this](int x, int y)
    {
       std::cout << "mouse down @ " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseDown(x, y, color);
       update_label();
    });
    //Register Handlers
    connect (ui->clearButton,SIGNAL (released()), this, SLOT (handleButton()));
    connect (ui->redSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideRed(int)));
    connect (ui->greenSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideGreen(int)));
    connect (ui->blueSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideBlue(int)));
    connect (ui->sizeBox, SIGNAL(valueChanged(int)),this ,SLOT(ChangeSize(int)));
    connect (ui->actionDot,SIGNAL(triggered(bool)), this, SLOT(SetBrushDot()));
    connect (ui->actionLine,SIGNAL(triggered(bool)), this, SLOT(SetBrushLine()));

    label_->setParent(ui->paint)  ;
    ui->selectedColor->setAutoFillBackground(true);
    update_label();

}

void MainWindow::SetBrushDot()
{
    std::cout << "Set standart Brush" << std::endl;
    activeBrush = new my::Brush(&image_, (*activeBrush).GetSize());
}
void MainWindow::SetBrushLine()
{
    std::cout << "SetLine Brush" << std::endl;
    activeBrush = new my::LineBrush(&image_, (*activeBrush).GetSize());
}

void MainWindow::ChangeSize(int val){
    (*activeBrush).SetSize(val);
}

//Gets Triggert if the one of the sliders is moved
void MainWindow::SlideRed(int val){
    std::cout << "red slide " << val << std::endl;
    activeColor.setRed(val);
    SetSelectedColor();
}
void MainWindow::SlideGreen(int val){
    std::cout << "green slide " << val << std::endl;
    activeColor.setGreen(val);
    SetSelectedColor();
}
void MainWindow::SlideBlue(int val){
    std::cout << "blue slide " << val << std::endl;
    activeColor.setBlue(val);
    SetSelectedColor();
}
//Set the Current Color to the Area to show it
void MainWindow::SetSelectedColor(){
    QPalette pal = ui->selectedColor->palette();
    pal.setColor(QPalette::Background, activeColor);
    ui->selectedColor->setPalette(pal);
}



void MainWindow::UpdateImage()
{
    auto qimage = QImage(
        reinterpret_cast<uchar const*>(image_.data()), image_.width(), image_.height(),
        sizeof(my::Image::rgba_t)*image_.width(), QImage::Format_ARGB32
     );

     label_->setPixmap(QPixmap::fromImage( qimage ));
}
void MainWindow::handleButton()
{
    uint32_t color = GetActiveColorCode();
    std::cout << "button clear to " << color  << std::endl;
    image_.clear(color);
    UpdateImage();
}

std::uint32_t MainWindow::GetActiveColorCode(){
    QString qs = activeColor.name(QColor::HexArgb);
    qs.remove(0,1);
    bool npointr;
    std::uint32_t color = qs.toUInt(&npointr,16);
    return color;
}

MainWindow::~MainWindow()
{
    delete ui;
}
