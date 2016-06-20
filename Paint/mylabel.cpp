#include "mylabel.h"

#include <QMouseEvent>
#include <QDebug>

#include <tuple>


MyLabel::MyLabel( QWidget* parent ) : QLabel{ parent }
{
//   setMouseTracking(true);
}

void MyLabel::mouseMoveEvent( QMouseEvent* e )  { Q_EMIT onMouseMove( e->x(), e->y() ); }
void MyLabel::mousePressEvent( QMouseEvent* e ) { Q_EMIT onMouseDown( e->x(), e->y() ); }
