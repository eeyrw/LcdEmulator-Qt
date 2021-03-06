#ifndef FONTGENERATOR_H
#define FONTGENERATOR_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QVector>

class FontGenerator
{
public:
    FontGenerator();
    ~FontGenerator();
    FontGenerator(QPoint colRowSize, QPoint areaSize, QVector<uint8_t> customFontRawData);
    QPixmap genSingleCustomFontBitmap(QVector<uint8_t> raw, double unitWidth, double unitHeight);

    QPixmap genSingleFontBitmap(int fontIndex, double unitWidth, double unitHeight);
    void genMainFontBitmap(double unitWidth, double unitHeight);
    void genCustomFontBitmap(QVector<uint8_t> allRawData, double unitWidth, double unitHeight);
    void setColRowSize(QPoint size);
    QPoint getColRowSize();
    void getActualCursor(QPoint cursor, QPointF *actualCursor);

    void getActualCursor(int x, int y, QPointF *actualCursor);
    QPixmap getCharBitmap(char charNum);
    QColor getNegativePixelColor();
    void setNegativePixelColor(QColor negativePixelColor);
    QColor getPositivePixelColor();
    void setPositivePixelColor(QColor positivePixelColor);
    QColor getLcdPanelColor();
    void setLcdPanelColor(QColor lcdPanelColor);
    void reGenFont();

private:
    double mUnitWidth;
    double mUnitHeight;

    double mCharWidthOffset;
    double mCharHeightOffset;

    double mSurfaceWidth;
    double mSurfaceHeight;

    QVector<QPixmap> mFontBitmapMain;
    QVector<QPixmap> mFontBitmapCustom;

    QVector<uint8_t> mCustomFontRawData;

    double mPixelSpaceWeight = 1.3;
    double mPixelWeight = 5;
    double mCharSpaceWeight = 5;
    double mMarginWeight = 12;

    double mPixelsPerRow = 5;
    double mPixelsPerCol = 8;

    int mBytesPerFont = 5;

    QPoint mColRowSize;

    QColor mPositivePixelColor = Qt::white;
    QColor mNegativePixelColor = QColor("#009999");
    QColor mLcdPanelColor = QColor("#006666");
};

#endif // FONTGENERATOR_H
