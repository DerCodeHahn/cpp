#pragma once

#include <QMainWindow>
#include "image.h"

class MainWindow : public QMainWindow
{
   Q_OBJECT

   class MyLabel*  label_;
   my::image       image_;

public:

   MainWindow( QWidget* = nullptr );
};
