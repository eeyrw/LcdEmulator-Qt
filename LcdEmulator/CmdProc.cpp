#include "CmdProc.h"


#define EVENT_FRAME_FLAG 0x776E //ASCII:"wn"

#define CMD_LCD_INIT 0x01
#define CMD_LCD_SETBACKLGIHT 0x02
#define CMD_LCD_SETCONTRAST 0x03
#define CMD_LCD_SETBRIGHTNESS 0x04
#define CMD_LCD_WRITEDATA 0x05
#define CMD_LCD_SETCURSOR 0x06
#define CMD_LCD_CUSTOMCHAR 0x07
#define CMD_LCD_WRITECMD 0x08
#define CMD_ECHO 0x09
#define CMD_GET_VER_INFO 0x0A
#define CMD_LCD_DE_INIT 0x0B
#define CMD_ENTER_BOOT 0x19

#define CMD_OFFEST 0x03

typedef enum _EVENT_FRAME_PARSER_STATUS {
    FRAME_PARSER_STATUS_IDLE = 0,
    FRAME_PARSER_STATUS_SOF_LO,
    FRAME_PARSER_STATUS_SOF_HI,
    FRAME_PARSER_STATUS_RECV_CMD_LEN,

} EVENT_FRAME_PARSER_STATUS;

static EVENT_FRAME_PARSER_STATUS frameParseStatus;

static uint8_t cmdBuf[256];
static uint8_t cmdRetBuf[256];

CharLcmView* defaultLcmView;

uint8_t *GetCmdDataPtr(uint8_t *buffer)
{
    return buffer + CMD_OFFEST;
}

int Protocol_Process(unsigned char *Buf)
{
    unsigned int i;
    int retByteNum = 0;
    uint8_t *rbf;

    switch (Buf[0])
    {
    case CMD_LCD_INIT:
        //		lcd = LiquidCrystal_I2C(0x3F, Buf[1], Buf[2], LCD_5x8DOTS);
        //		lcd.begin();
        //		lcd.clear();
        //printf("CMD_LCD_INIT.X=%d,Y=%d\n", Buf[1], Buf[2]);
        defaultLcmView->setColRow(Buf[1], Buf[2]);
        //defaultLcmView->clearScreen();
        //defaultLcmView->reGenResoures();

        break;

    case CMD_LCD_SETBACKLGIHT:
        //printf("CMD_LCD_SETBACKLGIHT.Level=%d\n", Buf[1]);
        if (Buf[1])
        {
            //lcd.backlight();
        }
        else
        {
            //lcd.noBacklight();
        }

        break;

    case CMD_LCD_SETCONTRAST:
        //printf("CMD_LCD_SETCONTRAST.Level=%d\n", Buf[1]);

        break;

    case CMD_LCD_SETBRIGHTNESS:
        //printf("CMD_LCD_SETCONTRAST.Level=%d\n", Buf[1]);

        break;

    case CMD_LCD_WRITEDATA:
        //qDebug()<<"CMD_LCD_WRITEDATA LEN:"<<Buf[1];
        //		for (i = 0; i < Buf[1]; i++)
        //		{
        //			lcd.write(Buf[2 + i]);
        //		}
        defaultLcmView->write((const char*)&Buf[2],Buf[1]);

        break;

    case CMD_LCD_SETCURSOR:
        //qDebug()<<"CMD_LCD_SETCURSOR"<<" "<<Buf[1]<<" "<<Buf[2];
        //printf("CMD_LCD_SETCURSOR.X=%d,Y=%d\n", Buf[1], Buf[2]);
        //lcd.setCursor(Buf[1], Buf[2]);
        defaultLcmView->setCursor(Buf[1], Buf[2]);

        break;

    case CMD_LCD_CUSTOMCHAR:
        //printf("CMD_LCD_CUSTOMCHAR.\n");
        //lcd.createChar(Buf[1], &Buf[2]);
        uint8_t font[8];
        memcpy(font,&Buf[2],8);
        // Reverse bit
        for (int i = 0; i < sizeof(font); i++) {
            uint8_t x = font[i];
            uint8_t b = 0;

            for (int bit = 4; bit >= 0; bit--) {
                if ((x & 1 << bit) != 0)
                    b |= 1 << (4 - bit);

            }
            font[i] = b;
        }

        defaultLcmView->setCustomFont(Buf[1], font,8);
        break;

    case CMD_LCD_WRITECMD:
        //printf("CMD_LCD_COMMAND: 0x%X.\n", Buf[1]);
        //lcd.command(Buf[1]);

        break;

    case CMD_ECHO:
        rbf = GetCmdDataPtr(cmdRetBuf);
        rbf[0] = CMD_ECHO;
        for (i = 1; i < Buf[1] + 1 + 1; i++)
        {
            rbf[i] = Buf[i];
        }
        retByteNum = Buf[1] + 1 + 1;
        break;

    case CMD_GET_VER_INFO:
        rbf = GetCmdDataPtr(cmdRetBuf);
        rbf[0] = CMD_GET_VER_INFO;
        //rbf[1] = sprintf((char *)&rbf[2], "Date: %s, Time: %s, Git: %s, Env: %s", _BuildInfo.date, _BuildInfo.time, _BuildInfo.src_version, _BuildInfo.env_version);
        retByteNum = rbf[1] + 1 + 1;
        break;
    case CMD_LCD_DE_INIT:
        //LcdShowStandby();

        break;
    case CMD_ENTER_BOOT:

    default:
        break;
    }
    return retByteNum;
}

bool ParseEventFrameStream(QTcpSocket *client)
{
    uint8_t streamByte;
    static uint8_t cmdLen = 0;
    bool processStatus = false;

    switch (frameParseStatus)
    {
    case FRAME_PARSER_STATUS_IDLE:
    {
        if (client->bytesAvailable())
        {
            client->read((char*)&streamByte,1);
            if (streamByte == ((uint8_t)(0xFF & EVENT_FRAME_FLAG)))
            {
                frameParseStatus = FRAME_PARSER_STATUS_SOF_LO;
                processStatus = true;
            }
        }
    }
        break;
    case FRAME_PARSER_STATUS_SOF_LO:
    {
        if (client->bytesAvailable())
        {
            client->read((char*)&streamByte,1);
            if (streamByte == ((uint8_t)(0xFF & (EVENT_FRAME_FLAG >> 8))))
            {
                frameParseStatus = FRAME_PARSER_STATUS_SOF_HI;
                processStatus = true;
            }
        }
    }
        break;
    case FRAME_PARSER_STATUS_SOF_HI:
    {
        if (client->bytesAvailable())
        {
            client->read((char*)&streamByte,1);
            cmdLen = streamByte;
            frameParseStatus = FRAME_PARSER_STATUS_RECV_CMD_LEN;
                processStatus = true;
        }
    }
        break;

    case FRAME_PARSER_STATUS_RECV_CMD_LEN:
    {
        if (client->bytesAvailable() >= cmdLen)
        {
            client->read((char*)cmdBuf, cmdLen);
            int retByteNum = Protocol_Process(cmdBuf);
            if (retByteNum > 0)
            {
                cmdRetBuf[0] = (uint8_t)(0xFF & EVENT_FRAME_FLAG);
                cmdRetBuf[1] = (uint8_t)(0xFF & (EVENT_FRAME_FLAG >> 8));
                cmdRetBuf[2] = retByteNum;
                retByteNum += 3;
                client->write((const char*)cmdRetBuf, retByteNum);
            }

            frameParseStatus = FRAME_PARSER_STATUS_IDLE;
                processStatus = true;
            cmdLen = 0;
        }
    }
        break;

    default:
        break;
    }
    return processStatus;
}
