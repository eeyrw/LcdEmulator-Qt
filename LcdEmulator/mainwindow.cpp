#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <tcpserver.h>
#include "CmdProc.h"
#include <QNetworkInterface>

QString getHostIpAddress()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 获取第一个本主机的IPv4地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; ++i)
    {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               strIpAddress = ipAddressesList.at(i).toString();
               break;
           }
     }
     // 如果没有找到，则以本地IP地址为IP
     if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
     return strIpAddress;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    defaultLcmView =ui->charLcmView;
    TcpServer *piServer = new TcpServer;
    ui->charLcmView->setCursor(0,0);
    ui->charLcmView->writeStr(getHostIpAddress());}

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
