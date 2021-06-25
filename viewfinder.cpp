#include "viewfinder.h"
#include <QPainter>
#include <QImage>

ViewFinder::ViewFinder(QWidget* parent)
    :QLabel(parent)
{

}

ViewFinder::~ViewFinder()
{

}

void ViewFinder::paintEvent(QPaintEvent* event)
{
   QLabel::paintEvent(event);

   QString rect_path = ":/images/face_detect_bg.png";
   QImage img(rect_path);

   QPainter painter(this);
   painter.drawImage(0, 0,img);
}
