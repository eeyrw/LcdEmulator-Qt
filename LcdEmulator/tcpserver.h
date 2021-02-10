#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

    void StartListen(int nPort);

private:
    QTcpServer *m_piserver;
    QTcpSocket *m_pisocket;

signals:

public slots:
    void newClientConnect();
    void readMessage();
    void disConnect();
};

#endif // TCPSERVER_H
