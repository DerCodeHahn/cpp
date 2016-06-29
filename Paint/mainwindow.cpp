#include "mainwindow.h"
#include "mylabel.h"
#include "ui_mainwindow.h"
#include "brush.h"

#include <QPixmap>
#include <QTimer>
#include <iostream>
#include <chrono>

#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , label_       { new MyLabel(this) }
    , image_       { 1000, 1000}
    , activeBrush { new my::Brush() }// = my::Brush(&image_,1);
{
    ui->setupUi(this);

    colorfader = my::ColorFader();
    rainbowTimer = new QTimer (this);
    connect(rainbowTimer, &QTimer::timeout, this, &MainWindow::UpdateRainbow);

    gameOfLifeTimer = new QTimer (this);
    connect(gameOfLifeTimer, &QTimer::timeout, this, &MainWindow::UpdateGameOfLife);


    activeBrush = new my::Brush(&image_,1);
    activeColor = QColor(0,0,0,255);
    //activeBrush = my::Brush(&image_, 3);

    connect( label_, &MyLabel::onMouseMove, [this](int x, int y)
    {
       std::cout << "mouse move: " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       //image_.set_pixel( x, y, color );
       (*activeBrush).OnMouseMove(x, y, color);
       this->UpdateImage();
    });

    connect( label_, &MyLabel::onMouseDown, [this](int x, int y)
    {
       std::cout << "mouse down @ " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseDown(x, y, color);
       this->UpdateImage();
    });
    //Register Handlers
    connect (ui->clearButton, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect (ui->redSlider, &QSlider::valueChanged,this , &MainWindow::SlideRed);
    connect (ui->greenSlider, &QSlider::valueChanged,this , &MainWindow::SlideGreen);
    connect (ui->blueSlider, &QSlider::valueChanged,this , &MainWindow::SlideBlue);
    connect (ui->sizeBox, SIGNAL(valueChanged(int)),this ,SLOT(ChangeSize(int)));
    connect (ui->actionDot, &QAction::triggered, this, &MainWindow::SetBrushDot);
    connect (ui->actionLine, &QAction::triggered, this, &MainWindow::SetBrushLine);
    connect (ui->RainbowBox, &QCheckBox::toggled, this, &MainWindow::ToggleRainbowMode);
    connect (ui->GameOfLifeBtn, &QPushButton::clicked, this, &MainWindow::StartGameOfLife);

    label_->setParent(ui->paint);
    ui->selectedColor->setAutoFillBackground(true);
    SetSelectedColor();
    //update_label();
    UpdateImage();
}

void MainWindow::StartGameOfLife(){
    game = my::GameOfLife(&image_, false);
    gameOfLifeTimer->start(500);
    std::cout << "Game of Life Start " << std::endl;

}

void MainWindow::UpdateGameOfLife() {
    auto start = std::chrono::steady_clock::now();
    game.Update();
    auto duration = std::chrono::duration_cast< std::chrono::milliseconds   >(std::chrono::steady_clock::now() - start);

    std::cout << "Game of Life Update "  << duration.count() << " ms "<< std::endl;
    UpdateImage();
}

void MainWindow::ToggleRainbowMode(bool checked){
    if(checked)
    {
        rainbowTimer->start(1);
    }
    else
    {
        rainbowTimer->stop();
    }
}

void MainWindow::UpdateRainbow(){

    colorfader.Update();
    std::vector<int> c = colorfader.getColor();
    activeColor.setRed(c[0]);
    activeColor.setGreen(c[1]);
    activeColor.setBlue(c[2]);
    //std::cout << "Rainbow " << c[0] << " " << c[1]<< " "<< c[2] << std::endl;
    SetSelectedColor();
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

    const std::vector<uint32_t> data = image_.getData();
       auto qimage = QImage(
          reinterpret_cast<uchar const*>(data.data()), image_.width(), image_.height(),
          sizeof(my::Image::pixel_t)*image_.width(), QImage::Format_ARGB32
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

void MainWindow::on_actionDot_triggered()
{
    SetBrushDot();
}
