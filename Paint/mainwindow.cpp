#include "mainwindow.h"
#include "mylabel.h"
#include "ui_mainwindow.h"
#include "brush.h"
#include "patternbrush.h"

#include <QPixmap>
#include <QTimer>
#include <iostream>
#include <chrono>
#include <QFileDialog>
#include <QFile>
#include <QImageReader>
#include <QCoreApplication>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , label_       { new MyLabel(this) }
    , history       { my::Image(400, 400)}
    , activeBrush { new my::Brush() }
{
    ui->setupUi(this);

    colorfader = my::ColorFader();
    rainbowTimer = new QTimer (this);
    connect(rainbowTimer, &QTimer::timeout, this, &MainWindow::UpdateRainbow);

    gameOfLifeTimer = new QTimer (this);
    connect(gameOfLifeTimer, &QTimer::timeout, this, &MainWindow::UpdateGameOfLife);

    ui->listWidget->addItem("Test");
    activeBrush = new my::Brush(&history,1);
    activeColor = QColor(0,0,0,255);

    for(my::PatternBrush::Pattern p : my::PatternBrush::GetPatterns())
        ui->patternBox->addItem(QString::fromStdString( p.name));

    connect( label_, &MyLabel::onMouseMove, [this](int x, int y)
    {
       //std::cout << "mouse move: " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseMove(x, y, color);
       this->UpdateImage();
    });

    connect( label_, &MyLabel::onMouseDown, [this](int x, int y)
    {
        history.Commit((*activeBrush).Description);
       //std::cout << "mouse down @ " << x << ", " << y << std::endl;
       int color = (int) GetActiveColorCode();
       (*activeBrush).OnMouseDown(x, y, color);
       this->UpdateImage();


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
    connect (ui->actionStraight_LIne, &QAction::triggered, this, &MainWindow::SetBrushStraightLine);
    connect (ui->RainbowBox, &QCheckBox::toggled, this, &MainWindow::ToggleRainbowMode);
    connect (ui->GameOfLifeBtn, &QPushButton::clicked, this, &MainWindow::StartGameOfLife);
    connect (ui->actionBack, &QAction::triggered, this, &MainWindow::Undo);
    connect (ui->actionOpen, &QAction::triggered, this, &MainWindow::OpenFile);
    connect (ui->action_2, &QAction::triggered, this, &MainWindow::Save);
    connect (ui->patternBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SetPatternBrush(int)));

    connect(ui->actionColor, &QAction::triggered, this, &MainWindow::ColorDialog);
    connect(ui->colorSelector, &QPushButton::clicked, this, &MainWindow::ColorDialog);
    connect(ui->listWidget, &QListWidget::currentRowChanged,this, &MainWindow::GetHistoryImage);

    label_->setParent(ui->paint);
    SetSelectedColor();
    UpdateImage();
}

void MainWindow::GetHistoryImage(int img){
    if(img == -1)
        return;
    std::cout << " History " << img << "/" << history.GetNameList().size() << std::endl;
    my::Image& tempImg = history.GetImage(img);
    ShowImage(tempImg);
}

void MainWindow::SetPatternBrush(int val){
    my::PatternBrush::Pattern p = my::PatternBrush::GetPatterns()[val];
    std::cout << "setBrush" << p.name <<std::endl;
    activeBrush = new my::PatternBrush(&history, val);
}

void MainWindow::Save(){
    QString name = QFileDialog::getSaveFileName(this, tr("Save File"),
                                           "ultraImg.jpg",
                                           tr("Images (*.png *.xpm *.jpg)"));
    label_->pixmap()->save(name,0, 100);
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

void MainWindow::SetBrushStraightLine()
{
    std::cout << "Set Straight Line Brush" << std::endl;
    activeBrush = new my::StraightLineBrush(&history, (*activeBrush).GetSize());
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
    QString s("background: #"
              + QString(activeColor.red() < 16? "0" : "") + QString::number(activeColor.red(),16)
              + QString(activeColor.green() < 16? "0" : "") + QString::number(activeColor.green(),16)
              + QString(activeColor.blue() < 16? "0" : "") + QString::number(activeColor.blue(),16) + ";");
    ui->colorSelector->setStyleSheet(s);
    ui->colorSelector->update();
}

void MainWindow::UpdateImage()
{
    my::Image& img = history.Current();
    ShowImage(img);
}

void MainWindow::ShowImage(my::Image img){
    const std::vector<uint32_t> data = img.getData();
       auto qimage = QImage(
          reinterpret_cast<uchar const*>(data.data()), img.width(), img.height(),
          sizeof(my::Image::pixel_t)*img.width(), QImage::Format_ARGB32
       );
    label_->setPixmap(QPixmap::fromImage( qimage ));
    UpdateHistory();
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

void MainWindow::ColorDialog(){
    QColor color = QColorDialog::getColor(activeColor, this);
    if(color.isValid()){
        activeColor = color;
        SetSelectedColor();
    }
}

void MainWindow::UpdateHistory(){
    ui->listWidget->clear();
    std::vector<std::string> list  = history.GetNameList();
    std::reverse(list.begin(), list.end());
    for(std::string s : list)
        ui->listWidget->addItem(QString::fromStdString(s));
}
