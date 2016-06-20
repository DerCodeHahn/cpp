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

    connect( ui->clearButton,SIGNAL (released()), this, SLOT (handleButton()));

    label_->setParent(ui->paint);
    update_label();

    //setCentralWidget(label_);
}


void MainWindow::handleButton()
{
    std::cout << "button clear" << std::endl;
    image_.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
