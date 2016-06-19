#pragma once

#include <QLabel>

// This class merely translates the mouse events that can only be reached via inharitance
// as signals so we can connect to them.

class MyLabel : public QLabel
{
   Q_OBJECT
public:

   MyLabel( QWidget* = nullptr );

   void mouseMoveEvent( QMouseEvent* ) override;
   void mousePressEvent( QMouseEvent* ) override;

   Q_SIGNAL void onMouseMove(int,int);
   Q_SIGNAL void onMouseDown(int,int);
   Q_SIGNAL void onMouseUp(int,int);
};

