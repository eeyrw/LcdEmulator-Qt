#include "fontgenerator.h"
const uint8_t mRawFontsData[] = {
    // 纵向排列的。
    0x00, 0x00, 0x00, 0x00, 0x00, // ' '
    0x00, 0x00, 0x5F, 0x00, 0x00, // !
    0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x14, 0x7F, 0x14, 0x7F, 0x14, // #
    0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
    0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x37, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x1C, 0x22, 0x41, 0x00, // (
    0x00, 0x41, 0x22, 0x1C, 0x00, // )
    0x08, 0x2A, 0x1C, 0x2A, 0x08, // *
    0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x50, 0x30, 0x00, 0x00, // ,
    0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, // <
    0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x41, 0x22, 0x14, 0x08, 0x00, // >
    0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x32, 0x49, 0x79, 0x41, 0x3E, // @
    0x7E, 0x11, 0x11, 0x11, 0x7E, // A
    0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x7F, 0x09, 0x09, 0x01, 0x01, // F
    0x3E, 0x41, 0x41, 0x51, 0x32, // G
    0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x7F, 0x02, 0x04, 0x02, 0x7F, // M
    0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x7F, 0x20, 0x18, 0x20, 0x7F, // W
    0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x03, 0x04, 0x78, 0x04, 0x03, // Y
    0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x00, 0x7F, 0x41, 0x41, // [
    0x02, 0x04, 0x08, 0x10, 0x20, // "\"
    0x41, 0x41, 0x7F, 0x00, 0x00, // ]
    0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x01, 0x02, 0x04, 0x00, // `
    0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x08, 0x14, 0x54, 0x54, 0x3C, // g
    0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x20, 0x40, 0x44, 0x3D, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, // k
    0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x7C, 0x14, 0x14, 0x14, 0x08, // p
    0x08, 0x14, 0x14, 0x18, 0x7C, // q
    0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x0C, 0x50, 0x50, 0x50, 0x3C, // y
    0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x00, 0x08, 0x36, 0x41, 0x00, // {
    0x00, 0x00, 0x7F, 0x00, 0x00, // |
    0x00, 0x41, 0x36, 0x08, 0x00, // }
    0x02, 0x01, 0x02, 0x04, 0x02, // ~
    0xff, 0xff, 0xff, 0xff, 0xff  // black
                                  // block
};
FontGenerator::FontGenerator() // 默认构造函数
{
    //这里面做一些变量内存分配的事..
}
FontGenerator::FontGenerator(QPoint colRowSize, QPoint areaSize, QVector<uint8_t> customFontRawData)
{

    mColRowSize = colRowSize;
    mSurfaceWidth = areaSize.x();
    mSurfaceHeight = areaSize.y();
    mCustomFontRawData = customFontRawData;
    // reGenFont();
}

void FontGenerator::reGenFont()
{
    double colNum = mColRowSize.x();
    double rowNum = mColRowSize.y();

    // mMarginWeight*2+colNum*(mPixelWeight*mPixelsPerRow+mPixelSpaceWeight*(mPixelsPerRow-1))+(colNum-1)*mCharSpaceWeight
    mUnitWidth = mSurfaceWidth / (mMarginWeight * 2 + colNum * (mPixelWeight * mPixelsPerRow + mPixelSpaceWeight * (mPixelsPerRow - 1)) + (colNum - 1) * mCharSpaceWeight);
    // mMarginWeight*2+rowNum*(mPixelWeight*mPixelsPerCol+mPixelSpaceWeight*(mPixelsPerCol-1))+(rowNum-1)*2*mCharSpaceWeight
    mUnitHeight = mSurfaceHeight / (mMarginWeight * 2 + rowNum * (mPixelWeight * mPixelsPerCol + mPixelSpaceWeight * (mPixelsPerCol - 1)) + (rowNum - 1) * 2 * mCharSpaceWeight);

    genMainFontBitmap(mUnitWidth, mUnitHeight);
    genCustomFontBitmap(mCustomFontRawData, mUnitWidth, mUnitHeight);

    mCharWidthOffset = mUnitWidth * (mPixelWeight * mPixelsPerRow + mPixelSpaceWeight * (mPixelsPerRow - 1) + mCharSpaceWeight);
    mCharHeightOffset = mUnitHeight * (mPixelWeight * mPixelsPerCol + mPixelSpaceWeight * (mPixelsPerCol - 1) + mCharSpaceWeight * 2);
}

QPixmap FontGenerator::genSingleCustomFontBitmap(QVector<uint8_t> raw, double unitWidth, double unitHeight)
{

    int bitmapWidth = (int)(unitWidth * (mPixelWeight * mPixelsPerRow + mPixelSpaceWeight * (mPixelsPerRow - 1)));
    int bitmapHeight = (int)(unitHeight * (mPixelWeight * mPixelsPerCol + mPixelSpaceWeight * (mPixelsPerCol - 1)));

    QPixmap fontBitmap = QPixmap(bitmapWidth, bitmapHeight);
    fontBitmap.fill(mLcdPanelColor);
    QPainter painter(&fontBitmap);

    double charPixelWidth = mUnitWidth * mPixelWeight;
    double charPixelHeight = mUnitHeight * mPixelWeight;

    //设置画刷

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < mPixelsPerCol; ++y)
    {
        for (int x = 0; x < mPixelsPerRow; ++x)
        {

            double pixelRectLeft = x * (charPixelWidth + mPixelSpaceWeight * mUnitWidth);
            double pixelRectTop = y * (charPixelHeight + mPixelSpaceWeight * mUnitHeight);

            QRectF pixelRect = QRectF(pixelRectLeft, pixelRectTop,
                                      charPixelWidth, charPixelHeight);
            if ((raw[y] & (1 << x)) != 0)
            {
                brush.setColor(mPositivePixelColor);
                painter.setBrush(brush);
            }
            else
            {
                brush.setColor(mNegativePixelColor);
                painter.setBrush(brush);
            }
            painter.drawRect(pixelRect);
        }
    }
    return fontBitmap;
}

QPixmap FontGenerator::genSingleFontBitmap(int fontIndex, double unitWidth, double unitHeight)
{
    int bitmapWidth = (int)(unitWidth * (mPixelWeight * mPixelsPerRow + mPixelSpaceWeight * (mPixelsPerRow - 1)));
    int bitmapHeight = (int)(unitHeight * (mPixelWeight * mPixelsPerCol + mPixelSpaceWeight * (mPixelsPerCol - 1)));

    QPixmap fontBitmap = QPixmap(bitmapWidth, bitmapHeight);
    fontBitmap.fill(mLcdPanelColor);
    QPainter painter(&fontBitmap);

    double charPixelWidth = mUnitWidth * mPixelWeight;
    double charPixelHeight = mUnitHeight * mPixelWeight;

    //设置画刷

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < mPixelsPerCol; ++y)
    {
        for (int x = 0; x < mPixelsPerRow; ++x)
        {

            double pixelRectLeft = x * (charPixelWidth + mPixelSpaceWeight * mUnitWidth);
            double pixelRectTop = y * (charPixelHeight + mPixelSpaceWeight * mUnitHeight);

            QRectF pixelRect = QRectF(pixelRectLeft, pixelRectTop,
                                      charPixelWidth, charPixelHeight);
            if ((mRawFontsData[(int)(fontIndex * mPixelsPerRow + x)] & (1 << y)) != 0)
            {
                brush.setColor(mPositivePixelColor);
                painter.setBrush(brush);
            }
            else
            {
                brush.setColor(mNegativePixelColor);
                painter.setBrush(brush);
            }
            painter.drawRect(pixelRect);
        }
    }

    return fontBitmap;
}

void FontGenerator::genMainFontBitmap(double unitWidth, double unitHeight)
{

    int fontNum = sizeof(mRawFontsData) / mBytesPerFont;

    mFontBitmapMain = QVector<QPixmap>(fontNum);

    for (int fontIndex = 0; fontIndex < fontNum; ++fontIndex)
    {
        mFontBitmapMain[fontIndex] = genSingleFontBitmap(fontIndex,
                                                         unitWidth, unitHeight);
    }
    //Log.i(TAG, "Custom font generated.");
}

void FontGenerator::genCustomFontBitmap(QVector<uint8_t> allRawData, double unitWidth, double unitHeight)
{

    int fontNum = 8;

    mFontBitmapCustom = QVector<QPixmap>(fontNum);

    QVector<uint8_t> temp = QVector<uint8_t>(8);

    for (int fontIndex = 0; fontIndex < fontNum; ++fontIndex)
    {
        memcpy(temp.data(), allRawData.data() + fontIndex * 8, 8);
        mFontBitmapCustom[fontIndex] = genSingleCustomFontBitmap(temp,
                                                                 unitWidth, unitHeight);
    }
    //Log.i(TAG, "Main font generated.");
}

void FontGenerator::setColRowSize(QPoint size)
{
    mColRowSize = size;
}

QPoint FontGenerator::getColRowSize()
{
    return mColRowSize;
}

void FontGenerator::getActualCursor(QPoint cursor, QPointF *actualCursor)
{

    actualCursor->setX(mMarginWeight * mUnitWidth + mCharWidthOffset * cursor.x());
    actualCursor->setY(mMarginWeight * mUnitHeight + mCharHeightOffset * cursor.y());
}

void FontGenerator::getActualCursor(int x, int y, QPointF *actualCursor)
{
    QPoint t = QPoint(x, y);
    getActualCursor(t, actualCursor);
}

QPixmap FontGenerator::getCharBitmap(char charNum)
{
    // ' ' in ASCII is 32
    if (charNum >= 32 && charNum <= 127)
    {
        charNum -= 32;
    }
    else if (charNum >= 0 && charNum <= 7)
    {
        return mFontBitmapCustom[charNum];
    }
    else
    {
        charNum = 32;
    }

    return mFontBitmapMain[charNum];
}

QColor FontGenerator::getNegativePixelColor()
{
    return mNegativePixelColor;
}

void FontGenerator::setNegativePixelColor(QColor negativePixelColor)
{
    mNegativePixelColor = negativePixelColor;
}

QColor FontGenerator::getPositivePixelColor()
{
    return mPositivePixelColor;
}

void FontGenerator::setPositivePixelColor(QColor positivePixelColor)
{
    mPositivePixelColor = positivePixelColor;
}

QColor FontGenerator::getLcdPanelColor()
{
    return mLcdPanelColor;
}

void FontGenerator::setLcdPanelColor(QColor lcdPanelColor)
{
    mLcdPanelColor = lcdPanelColor;
}

FontGenerator::~FontGenerator()
{
    for (QPixmap &bitmap : mFontBitmapMain)
    {
        bitmap.~QPixmap();
    }
    for (QPixmap &bitmap : mFontBitmapCustom)
    {
        bitmap.~QPixmap();
    }

    //if(mFontBitmapCustom!=NULL)
    // delete mFontBitmapCustom;
    // if(mCustomFontRawData!=NULL)
    // delete mCustomFontRawData;
}
