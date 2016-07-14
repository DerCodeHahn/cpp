#include "mainwindow.h"
#include "mylabel.h"
#include "ui_mainwindow.h"
#include "brush.h"

#include <QPixmap>
#include <QTimer>
#include <iostream>
#include <chrono>
#include <QFileDialog>
#include <QFile>
#include <QImageReader>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , label_       { new MyLabel(this) }
    , history       { my::Image(400, 400)}
    , activeBrush { new my::Brush() }// = my::Brush(&image_,1);
{
    ui->setupUi(this);

    colorfader = my::ColorFader();
    rainbowTimer = new QTimer (this);
    connect(rainbowTimer, &QTimer::timeout, this, &MainWindow::UpdateRainbow);

    gameOfLifeTimer = new QTimer (this);
    connect(gameOfLifeTimer, &QTimer::timeout, this, &MainWindow::UpdateGameOfLife);


    activeBrush = new my::Brush(&history,1);
    activeColor = QColor(0,0,0,255);

    connect( label_, &MyLabel::onMouseMove, [this](int x, int y)
    {
       //std::cout << "mouse move: " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseMove(x, y, color);
       this->UpdateImage();
    });

    connect( label_, &MyLabel::onMouseDown, [this](int x, int y)
    {
       //std::cout << "mouse down @ " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseDown(x, y, color);
       this->UpdateImage();

       history.Commit("activeBrush");
    });
    connect( label_, &MyLabel::onMouseUp, [this](int x, int y)
    {
       //std::cout << "mouse up @ " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();

       (*activeBrush).OnMouseUp(x, y, color);
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
    connect (ui->actionRectangle, &QAction::triggered, this, &MainWindow::SetBrushRectangle);
    connect (ui->actionCircle, &QAction::triggered, this, &MainWindow::SetBrushCircle);
    connect (ui->RainbowBox, &QCheckBox::toggled, this, &MainWindow::ToggleRainbowMode);
    connect (ui->GameOfLifeBtn, &QPushButton::clicked, this, &MainWindow::StartGameOfLife);
    connect (ui->actionBack, &QAction::triggered, this, &MainWindow::Undo);
    connect (ui->actionOpen, &QAction::triggered, this, &MainWindow::OpenFile);
    connect (ui->action_2, &QAction::triggered, this, &MainWindow::Save);

    label_->setParent(ui->paint);
    ui->selectedColor->setAutoFillBackground(true);
    SetSelectedColor();
    //update_label();
    UpdateImage();
}

void MainWindow::Save(){
    QString name = QFileDialog::getSaveFileName(this, tr("Save File"),
                                           "/home/jana/untitled.jpg",
                                           tr("Images (*.png *.xpm *.jpg)"));
    label_->pixmap()->save(name,0, -1);

}

void MainWindow::Undo(){
    history.Undo();
    UpdateImage();
}

void MainWindow::StartGameOfLife(){
    game = my::GameOfLife( false);
    gameOfLifeTimer->start(500);
    std::cout << "Game of Life Start " << std::endl;

}

void MainWindow::UpdateGameOfLife() {
    auto start = std::chrono::steady_clock::now();
    game.Update(&history.Current());
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
void MainWindow::OpenFile(){
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    QImageReader reader(fileName);
    QImage img = reader.read();

    history.Commit("LoadImg");
    history.Current().SetData(img);
    UpdateImage();
    //label_->setPixmap(QPixmap::fromImage( img ));
    label_->resize(img.width(), img.height());
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
    activeBrush = new my::Brush(&history, (*activeBrush).GetSize());
}
void MainWindow::SetBrushLine()
{
    std::cout << "SetLine Brush" << std::endl;
    activeBrush = new my::LineBrush(&history, (*activeBrush).GetSize());
}
void MainWindow::SetBrushRectangle()
{
    std::cout << "Set Rectangle Brush" << std::endl;
    activeBrush = new my::RectangleBrush(&history, (*activeBrush).GetSize());
}

void MainWindow::SetBrushCircle()
{
    std::cout << "Set Circle Brush" << std::endl;
    activeBrush = new my::CircleBrush(&history, (*activeBrush).GetSize());
}

void MainWindow::ChangeSize(int val){
    (*activeBrush).SetSize(val);
}

//Gets Triggert if the one of the sliders is moved
void MainWindow::SlideRed(int val){
    //std::cout << "red slide " << val << std::endl;
    activeColor.setRed(val);
    SetSelectedColor();
}
void MainWindow::SlideGreen(int val){
    //std::cout << "green slide " << val << std::endl;
    activeColor.setGreen(val);
    SetSelectedColor();
}
void MainWindow::SlideBlue(int val){
    //std::cout << "blue slide " << val << std::endl;
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
    my::Image& img = history.Current();
    const std::vector<uint32_t> data = img.getData();
       auto qimage = QImage(
          reinterpret_cast<uchar const*>(data.data()), img.width(), img.height(),
          sizeof(my::Image::pixel_t)*img.width(), QImage::Format_ARGB32
       );
    label_->setPixmap(QPixmap::fromImage( qimage ));
}
void MainWindow::handleButton()
{
    uint32_t color = GetActiveColorCode();
    //std::cout << "button clear to " << color  << std::endl;
    history.Commit("Clear");
    history.Current().clear(color);

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
