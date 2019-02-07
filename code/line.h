#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QMainWindow>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QTime>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QtMath>

class line:public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene scene;
    QGraphicsItem *Line;
    QGraphicsItem *inLine;

    QPen pen;
    int num[2]; //前后的控制点数目
    int numm;
    int linetype; //0->start,1->end
    int drawtype;  //0->line,1->vector

    int x[2][100];
    int y[2][100];//初始和结束的线
    int inx[50][100];//中间过度线
    int iny[50][100];
    int inNum;

    QTimer *timer;

public:
    void addPoint(int _x,int _y);
    void addLine();
    void clear();
    void start();
    line();
    ~line();
    friend class MainWindow;

public slots:
    void nextflame();
};

#endif // LINE_H

