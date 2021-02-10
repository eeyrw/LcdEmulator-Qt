#include "tcpserver.h"


#include "tcpserver.h"
#include "QCoreApplication"
#include "CmdProc.h"

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    m_piserver = new QTcpServer;
    m_pisocket = new QTcpSocket;
    m_pisocket->setSocketOption(QTcpSocket::LowDelayOption,1);
    StartListen(2400);
}

void TcpServer::StartListen(int nPort)
{
    if(m_piserver->listen(QHostAddress::Any,nPort))
        qDebug() << "listen ok";
    else
        qDebug() << "listen err";
    connect(m_piserver,SIGNAL(newConnection()),this,SLOT(newClientConnect()));
}

void TcpServer::newClientConnect()
{
    qDebug() << "new client connect";
    m_pisocket = m_piserver->nextPendingConnection();
    connect(m_pisocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(m_pisocket,SIGNAL(disconnected()),this,SLOT(disConnect()));
}

void TcpServer::readMessage()
{
   // qDebug() << "read client message";
    //QByteArray buf;
    //buf = m_pisocket->readAll();

    while(int q = m_pisocket->bytesAvailable())
    {
      //qDebug() << "Available:"<<q;
        ParseEventFrameStream(m_pisocket);
    }
    //qDebug() << buf;
}

void TcpServer::disConnect()
{
    qDebug() << "client disconnect";
}

//#include <server.h>
//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    Server *piServer = new Server;
//    return a.exec();//开始主线程事件循环
//}
