
#include "RenderWidget.h"
#include <QPainter>
#include <cmath>
RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  
  myDrawLine(25,195,25,420);
  myDrawLine(25, 420, 365, 420);
  myDrawLine(365,195,365,420);
  myDrawLine(200,215, 250, 215);
  myDrawLine(200,215, 200, 255);

  myDrawLine(100, 215, 120, 215);
  myDrawLine(200, 115, 200, 135);

  myDrawLine(280, 215, 300, 215);
  myDrawLine(200, 295, 200, 315);

  myDrawARC(195,195,-360,-180,170);
  myDrawCircle(200, 215, 100);
}


void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
  QPainter painter(this);

  //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  float m = (y2 - y1) / (x2 - x1);
  //  SetPixel(x1, y1, color);   // first point
  painter.drawPoint(x1, y1);

  if (m < 1)
  {
    float y = y1;
    for (int i = x1 + 1; i < x2; ++i)
    {
      y = y + m;
      //      SetPixel(i, round(y), color);
      painter.drawPoint(i, round(y));
    }
  }
  else     // i.e., m > 1
  {
    float mm = 1 / m;
    float x = x1;
    for (int i = y1 + 1; i < y2; ++i)
    {
      x = x + mm;
      //      SetPixel(round(x), i, color);
      painter.drawPoint(round(x), i);
    }
  }

  //  SetPixel(x2, y2, color);   // last point
  painter.drawPoint(x2, y2);
}

 
 void RenderWidget::myDrawCircle(float xc, float yc, float r) {
     QPainter painter(this);
     QColor color(0, 0, 0);
     painter.setPen(QPen(color, 1));
      float theta = 0;
      float dt = 1 / r;
     while (theta <2*3.15)
     {
         float x = xc + r*cos(theta);
         float y =yc + r*sin(theta);
         painter.drawPoint(round(x),round( y));
         theta = theta + dt;

     }
     for (int m = 0; m < 60; ++m) {
         theta = m * 6 * 3.14 / 180;
         float x1 = xc + r * cos(theta);
         float y1 = yc + r * sin(theta);
         if (m % 5)
         {
             float x2 = xc + r * 0.95 * cos(theta);
             float y2 = yc + r * 0.95 * sin(theta);
             painter.drawLine(round(x1), round(y1), round(x2), round(y1));
         }
     }
 
 }
 
 void RenderWidget::myDrawARC(float xc, float yc, float t1, float t2, float r) {
     QPainter painter(this);
     QColor color(0, 0, 0);
     painter.setPen(QPen(color, 1));
     float PI = 3.14;
     float theta = t1, dTheta = 1 / r;
     float x, y;
     while (theta < t2)
     {
         x = xc + (r * cos(theta * 3.14 / 180));
         y = yc + (r * sin(theta * 3.14 / 180));
         painter.drawPoint(x, y);
         theta += dTheta;
     }


 }