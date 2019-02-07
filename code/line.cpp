#include"line.h"
#include <QPainter>
#define PI 3.141592

line::line()
{
    num[0] = 0;
    num[1] = 0;
    linetype = 0;
    drawtype = 0;
    Line = new QGraphicsLineItem;
    inLine = new QGraphicsLineItem;
    scene.addItem(Line);
    scene.addItem(inLine);
    pen.setBrush(Qt::green);
    pen.setWidth(3);
    pen.setStyle(Qt::DashDotLine);

    inNum = 0;
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(nextflame()));
    timer->stop();

}
line::~line(){
    delete Line;
    delete inLine;
}
void line::clear()
{
    num[0]=num[1]=0;
    scene.removeItem(Line);

    timer->stop();
}

void line::start()
{
    if(num[0]!=num[1])
    {
        return;
    }
    addLine();
    inNum=0;
    timer->start(100);
}
void line::addPoint(int _x, int _y)
{
    numm = num[linetype];
    x[linetype][numm]=_x;
    y[linetype][numm]=_y;
    num[linetype]++;
    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(_x,_y,5,5,Line);
    point->setPen(pen);
    if(num[linetype]==1)
        return;
    QGraphicsLineItem *linee = new QGraphicsLineItem(x[linetype][numm-1]+5,y[linetype][numm-1]+5,_x,_y,Line);
    linee->setPen(pen);
    return;
}
void line::addLine()
{
    if(drawtype==1)
    {
        int number;
        int x1,y1,x2,y2;
        double t,t1,t2,l,l1,l2;
        number=50;
        for(int j=0;j<50;j++){
            inx[j][0]=1/50.0*j*x[1][0]+1/50.0*(50-j)*x[0][0];
            iny[j][0]=1/50.0*j*y[1][0]+1/50.0*(50-j)*y[0][0];
        }
        for(int i=1;i<num[0];i++){
            x1=x[0][i]-x[0][i-1];
            y1=y[0][i]-y[0][i-1];
            x2=x[1][i]-x[1][i-1];
            y2=y[1][i]-y[1][i-1];
            t1=asin(y1/sqrt(qPow(x1,2)+qPow(y1,2)));
            t2=asin(y2/sqrt(qPow(x2,2)+qPow(y2,2)));
            if(x1<0)
                t1=(PI-t1);
            if(x2<0)
                t2=(PI-t2);
            l1=qPow(x[0][i]-x[0][i-1],2)+qPow(y[0][i]-y[0][i-1],2);
            l2=qPow(x[1][i]-x[1][i-1],2)+qPow(y[1][i]-y[1][i-1],2);
            l1=qSqrt(l1);
            l2=qSqrt(l2);
            while(qAbs(t1-t2)>PI)
            {
                if(t1>t2)
                {
                    t1-=PI*2;
                }
                else
                {
                    t2-=PI*2;
                }
            }
            for(int j=0;j<50;j++){
                t=1/50.0*j*t2+1/50.0*(50-j)*t1;
                l=1/50.0*j*l2+1/50.0*(50-j)*l1;
                inx[j][i]=inx[j][i-1]+l*qCos(t);
                iny[j][i]=iny[j][i-1]+l*qSin(t);
            }
        }
    }
    else
    {
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<num[0];j++)
            {
                inx[i][j] = 1/50.0*i*x[1][j]+1/50.0*(50-i)*x[0][j];
                iny[i][j] = 1/50.0*i*y[1][j]+1/50.0*(50-i)*y[0][j];
            }
        }
    }

}

void line::nextflame()
{
    QList<QGraphicsItem *> list_line = inLine->childItems();
    for ( int i=0; i!=list_line.size(); i++ )
    {
        scene.removeItem(list_line.at(i));
    }

    if(inNum==50)
        return;

    for(int i=0;i<num[0];i++)
    {
        QGraphicsEllipseItem *point = new QGraphicsEllipseItem(inx[inNum][i],iny[inNum][i],5,5,inLine);
        point->setPen(pen);
        if(i==0)
            continue;
        QGraphicsLineItem *linee = new QGraphicsLineItem(inx[inNum][i-1],iny[inNum][i-1],inx[inNum][i],iny[inNum][i],inLine);
        linee->setPen(pen);
    }
    inNum++;
}


