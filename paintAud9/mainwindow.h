#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QTimer>
#include "ui_mainwindow.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);
    
private slots:
    void draw_sfear(int);


private:
    Ui::mainwindowClass ui;
    //QScopedPointer<QPixmap> pixmap; 
    QPixmap* pixmap;
    //QTimer* timer = nullptr;
    
};
