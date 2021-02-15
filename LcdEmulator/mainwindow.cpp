#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <tcpserver.h>
#include "CmdProc.h"
#include <QNetworkInterface>
#include <QColorDialog>
#include <QSettings>

QString getHostIpAddress()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 获取第一个本主机的IPv4地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            strIpAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // 如果没有找到，则以本地IP地址为IP
    if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return strIpAddress;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    defaultLcmView = ui->charLcmView;
    TcpServer *piServer = new TcpServer;
    ui->charLcmView->setCursor(0, 0);
    ui->charLcmView->writeStr(getHostIpAddress());

    QCoreApplication::setOrganizationName("YUAN");
    QCoreApplication::setOrganizationDomain("github.com/eeyrw/LcdEmulator");
    QCoreApplication::setApplicationName("Char Lcm Emulator");

    QSettings settings;
    QColor color = settings.value("Color/LcdPanelColor", ui->charLcmView->getLcdPanelColor()).value<QColor>();
    ui->charLcmView->setLcdPanelColor(color);

    color = settings.value("Color/NegativePixelColor", ui->charLcmView->getNegativePixelColor()).value<QColor>();
    ui->charLcmView->setNegativePixelColor(color);

    color = settings.value("Color/PositivePixelColor", ui->charLcmView->getPositivePixelColor()).value<QColor>();
    ui->charLcmView->setPositivePixelColor(color);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSetBackColor_clicked()
{
    QColor currentColor = ui->charLcmView->getLcdPanelColor();
    QColor Color = QColorDialog::getColor(currentColor, this, "选择颜色"); //选择颜色
    if (Color.isValid())
    {
        ui->charLcmView->setLcdPanelColor(Color);
        QSettings settings;
        settings.setValue("Color/LcdPanelColor", Color);
    }
}

void MainWindow::on_btnSetGridColor_clicked()
{
    QColor currentColor = ui->charLcmView->getNegativePixelColor();
    QColor Color = QColorDialog::getColor(currentColor, this, "选择颜色"); //选择颜色
    if (Color.isValid())
    {
        ui->charLcmView->setNegativePixelColor(Color);
        QSettings settings;
        settings.setValue("Color/NegativePixelColor", Color);
    }
}

void MainWindow::on_btnSetPixelColor_clicked()
{
    QColor currentColor = ui->charLcmView->getPositivePixelColor();
    QColor Color = QColorDialog::getColor(currentColor, this, "选择颜色"); //选择颜色
    if (Color.isValid())
    {
        ui->charLcmView->setPositivePixelColor(Color);
        QSettings settings;
        settings.setValue("Color/PositivePixelColor", Color);
    }
}

void MainWindow::on_btnFullScreen_clicked()
{
    ui->charLcmView->switchFullScreen(true);
}


