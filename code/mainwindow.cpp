#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&linee.scene);
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clear()));
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(start()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(){
    linee.start();
}
void MainWindow::clear()
{
    linee.clear();
}
void MainWindow::on_startframe_clicked()
{
    linee.linetype=0;
}
void MainWindow::on_endframe_clicked()
{
    linee.linetype=1;
}
void MainWindow::on_linner_clicked()
{
    linee.drawtype=0;
}
void MainWindow::on_vector_clicked()
{
    linee.drawtype=1;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    linee.addPoint(event->x()-5,event->y()-5);
}
