#ifndef CHARLCMVIEW_H
#define CHARLCMVIEW_H

#include <QWidget>
#include <QPainter>
#include <fontgenerator.h>

class CharLcmView : public QWidget
{
    Q_OBJECT
private:
    // Color
    QColor mPositivePixelColor = Qt::white;
    QColor mNegativePixelColor = QColor("#009999");
    QColor mLcdPanelColor = QColor("#006666");

    // SurfaceView
    int mSurfaceHeight;
    int mSurfaceWidth;

    // Virtual LCM property
    int mColNum;
    int mRowNum;

    int mCursorX;
    int mCursorY;

    char *mLcmChars;
    QVector<uint8_t> mCustomCharsRaw;

    QString mText;

    // Font generation class instance
    FontGenerator mFontGen;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE; //绘图
public:
    explicit CharLcmView(QWidget *parent = nullptr);
    QColor getNegativePixelColor();
    void setNegativePixelColor(QColor mNegativePixelColor);
    QColor getPositivePixelColor();
    void setPositivePixelColor(QColor mPositivePixelColor);
    QColor getLcdPanelColor();
    void setLcdPanelColor(QColor mLcdPanelColor);
    QString getText();
    void setText(QString mText);
    void forceReDraw();
    void write(const char* data,int len);
    void writeStr(QString str);
    void setCustomFont(int index, QVector<uint8_t> rawdata, int len);
    void setCustomFont(int index, uint8_t* rawdata, int len);
    void clearScreen();
    void setCursor(int x, int y);
    void setCursor(QPoint cursor);
    void getCursor(int *x, int *y);
    void getCursor(QPoint *cursor);
    void reGenResoures();
    void setColRow(int col, int row);
    void getColRow(int col, int row);
    void resizeEvent(QResizeEvent *event);

signals:
public slots:
};

#endif // CHARLCMVIEW_H
