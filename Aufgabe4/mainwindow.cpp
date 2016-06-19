#include "mainwindow.h"
#include "mylabel.h"
#include <QPixmap>

#include <iostream>


MainWindow::MainWindow( QWidget* parent )
: QMainWindow  { parent }
, label_       { new MyLabel(this) }
, image_       { 400, 200 }
{
   // Updates the pixmap shown by label from the data of our custom image
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
      std::cout << "mouse move: " << x << ", " << y << std::endl;
      image_.set_pixel( x, y, 0xffeeaaaa );
      update_label();
   });

   connect( label_, &MyLabel::onMouseDown, [update_label,this](int x, int y)
   {
      std::cout << "mouse down @ " << x << ", " << y << std::endl;
      update_label();
   });


   update_label();
   setCentralWidget(label_);
}
