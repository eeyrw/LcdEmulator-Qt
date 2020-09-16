#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->charLcmView->writeStr(QString("sdgsgsdg"));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->charLcmView->setCursor(0,0);
    ui->charLcmView->writeStr(QString("Count:%1").arg(value));

}
