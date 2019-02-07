#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include "line.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    class line linee;
protected:
    void mousePressEvent(QMouseEvent *event);
public slots:
    void clear();
    void start();
private slots:
    void on_startframe_clicked();
    void on_endframe_clicked();
    void on_linner_clicked();
    void on_vector_clicked();
    
};

#endif // MAINWINDOW_H
