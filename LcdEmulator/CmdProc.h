#ifndef CMDPROC_H
#define CMDPROC_H

#include <cstdint>
#include "tcpserver.h"
#include <cstdio>
#include "charlcmview.h"

extern CharLcmView* defaultLcmView;
extern bool ParseEventFrameStream(QTcpSocket *client);
extern int Protocol_Process(unsigned char *Buf);
#endif // CMDPROC_H
