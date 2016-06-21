#include "mainwindow.h"
#include "mylabel.h"
#include "ui_mainwindow.h"
#include <QPixmap>

#include <iostream>

#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , label_       { new MyLabel(this) }
    , image_       { 800, 400 }
{
    ui->setupUi(this);
    activeColor = QColor(0,0,0,255);
    auto update_label = [this]
    {
       auto qimage = QImage(
          reinterpret_cast<uchar const*>(image_.data()), image_.width(), image_.height(),
          sizeof(my::image::rgba_t)*image_.width(), QImage::Format_ARGB32
       );

       label_->setPixmap(QPixmap::fromImage( qimage ));
    };

    connect( label_, &MyLabel::onMouseMove, [update_label,this](int x, int y)
    {
       std::cout << "mouse move: " << x << ", " << y << std::endl;
       image_.set_pixel( x, y, 0xffeeaaaa );
       update_label();
    });

    connect( label_, &MyLabel::onMouseDown, [update_label,this](int x, int y)
    {
       std::cout << "mouse down @ " << x << ", " << y << std::endl;
       update_label();
    });

    connect (ui->clearButton,SIGNAL (released()), this, SLOT (handleButton()));
    connect (ui->redSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideRed(int)));
    connect (ui->greenSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideGreen(int)));
    connect (ui->blueSlider, SIGNAL(valueChanged(int)),this ,SLOT(SlideBlue(int)));

    label_->setParent(ui->paint)  ;
    ui->selectedColor->setAutoFillBackground(true);
    update_label();

    //setCentralWidget(label_);
}

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

void MainWindow::SetSelectedColor(){
    QPalette pal = ui->selectedColor->palette();//.window().setColor(activeColor);// = QBrush(activeColor,Qt::SolidPattern );
    pal.setColor(QPalette::Background, activeColor);
    ui->selectedColor->setPalette(pal);
}



void MainWindow::UpdateImage()
{
    auto qimage = QImage(
        reinterpret_cast<uchar const*>(image_.data()), image_.width(), image_.height(),
        sizeof(my::image::rgba_t)*image_.width(), QImage::Format_ARGB32
     );

     label_->setPixmap(QPixmap::fromImage( qimage ));
}
void MainWindow::handleButton()
{
    std::cout << "button clear" << std::endl;
    image_.clear(activeColor.HexArgb);
    UpdateImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}
