#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.label->setFixedSize(500, 500);
    //pixmap.reset(new QPixmap(ui.label->width(),ui.label->height()));
    pixmap = new QPixmap(500, 500);
    pixmap->fill(Qt::white);
    //timer = new QTimer();
    //timer->setInterval(2000);    
    //connect(ui.startbutton, SIGNAL(released()), timer, SLOT(start()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(timer_round()));
    ui.verticalSlider->setRange(0, 5);
    draw_sfear(0);
    connect(ui.verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(draw_sfear(int)));
   
    
}

void mainwindow::draw_sfear(int r)
{
    QPainter painter(pixmap);
    pixmap->fill(Qt::white);
    painter.setPen(QPen(Qt::red,2.5,Qt::PenStyle::SolidLine));

    for (int i = 0; i < 10; i++)
    {        
        switch (i % 6)
        {
        case 0:
            painter.setPen(QPen(Qt::red, 2.5, Qt::PenStyle::SolidLine));
            break;
        case 1:
            painter.setPen(QPen(Qt::darkRed, 2.5, Qt::PenStyle::SolidLine));
            break;
        case 2:
            painter.setPen(QPen(Qt::yellow, 2.5, Qt::PenStyle::SolidLine));
            break;
        case 3:
            painter.setPen(QPen(Qt::green, 2.5, Qt::PenStyle::SolidLine));
            break;
        case 4:
            painter.setPen(QPen(Qt::blue, 2.5, Qt::PenStyle::SolidLine));
            break;
        case 5:
            painter.setPen(QPen(Qt::darkBlue, 2.5, Qt::PenStyle::SolidLine));
            break;
        }



        for (int j = 2; j < 10; j++)
        {
            painter.drawEllipse(175 + i, 125 - i * 2, (100 - i * 10 - j)*(r+1) , (100 - i * 10 - j)*(r+1));
        }

       
        painter.setPen(QPen(Qt::black, 2.5, Qt::PenStyle::SolidLine));
        painter.drawEllipse(175 + i, 125 - i * 2, (100 - i * 10)*(r+1), (100 - i * 10)*(r+1));
        
    }
    painter.setPen(QPen(Qt::white, 2.5, Qt::PenStyle::SolidLine));
    for (int i = 100; i < 500; i++)
    {
        for (int j = 100; j < 500; j++)
        {
            if (((i-175 - 50*(r+1) + 25*r)*(i -175 - 50*(r+1) + 25 * r) + (j - 125 -50*(r+1) + 25 * r)*(j - 125 -50*(r+1) + 25 * r)) > 100*27*(r+1))painter.drawPoint(i, j);
            
        }
    }
    ui.label->setPixmap(*pixmap);
    
   
}
