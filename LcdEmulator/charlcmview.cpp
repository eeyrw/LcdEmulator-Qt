#include "charlcmview.h"

CharLcmView::CharLcmView(QWidget *parent) : QWidget(parent)
{
    mText = "TEST";

    // Size
    mSurfaceHeight = 150;
    mSurfaceWidth = 400;
    mCursorX = 0;
    mCursorY = 0;
    mColNum = 20;
    mRowNum = 4;

    //
    mCustomCharsRaw = QVector<uint8_t>(8 * 8);

    for (int i = 0; i < 8 * 8; i++)
    {
        mCustomCharsRaw[i] = (char)0x23; // 特殊图样
    }

    mLcmChars = new char[mRowNum * mColNum];
    for (int i = 0; i < mRowNum * mColNum; i++)
    {
        mLcmChars[i] = ' '; // 空格字符
    }

    const std::string &stdS = mText.toStdString();
    const char *mTextCStyle = stdS.c_str();

    memcpy(mLcmChars, mTextCStyle, strlen(mTextCStyle) <= mRowNum * mColNum ? strlen(mTextCStyle) : mRowNum * mColNum);

    mFontGen = FontGenerator(QPoint(mColNum, mRowNum), QPoint(mSurfaceWidth, mSurfaceHeight), mCustomCharsRaw);

    forceReDraw();
}

QColor CharLcmView::getNegativePixelColor()
{
    return mNegativePixelColor;
}

void CharLcmView::setNegativePixelColor(QColor mNegativePixelColor)
{
    mNegativePixelColor = mNegativePixelColor;
}

QColor CharLcmView::getPositivePixelColor()
{
    return mPositivePixelColor;
}

void CharLcmView::setPositivePixelColor(QColor mPositivePixelColor)
{
    mPositivePixelColor = mPositivePixelColor;
}

QColor CharLcmView::getLcdPanelColor()
{
    return mLcdPanelColor;
}

void CharLcmView::setLcdPanelColor(QColor mLcdPanelColor)
{
    mLcdPanelColor = mLcdPanelColor;
}

QString CharLcmView::getText()
{
    return mText;
}

void CharLcmView::setText(QString mText)
{
    setCursor(0, 0);
    mText = mText;
    memcpy(mLcmChars, mText.toStdString().c_str(), strlen(mText.toStdString().c_str()) <= mRowNum * mColNum ? strlen(mText.toStdString().c_str()) : mRowNum * mColNum);

    forceReDraw();
}

void CharLcmView::forceReDraw()
{
    repaint();
}

void CharLcmView::writeStr(QString str)
{

    QPoint postion = QPoint(mCursorX, mCursorY);
    memcpy(mLcmChars + mCursorX + mCursorY * mColNum, str.toStdString().c_str(), strlen(str.toStdString().c_str()) + mCursorX + mCursorY * mColNum <= mRowNum * mColNum ? strlen(str.toStdString().c_str()) : mRowNum * mColNum);

    mCursorX += (mCursorX + mCursorY * mColNum + strlen(str.toStdString().c_str())) % mColNum;
    forceReDraw();
}

void CharLcmView::setCustomFont(int index, QVector<uint8_t> rawdata, int len)
{

    memcpy(mCustomCharsRaw.data() + index * 8, rawdata.data(), len);
    reGenResoures();
    forceReDraw();
}

void CharLcmView::clearScreen()
{

    for (int i = 0; i < mRowNum * mColNum; i++)
    {
        mLcmChars[i] = ' '; // 空格字符
    }
    mCursorX = 0;
    mCursorY = 0;
    forceReDraw();
}

void CharLcmView::setCursor(int x, int y)
{
    mCursorX = x;
    mCursorY = y;
}

void CharLcmView::setCursor(QPoint cursor)
{
    mCursorX = cursor.x();
    mCursorY = cursor.y();
}

void CharLcmView::getCursor(int *x, int *y)
{
    (*x) = mCursorX;
    (*y) = mCursorY;
}

void CharLcmView::getCursor(QPoint *cursor)
{
    cursor->setX(mCursorX);
    cursor->setY(mCursorY);
}

void CharLcmView::reGenResoures()
{
    mFontGen = FontGenerator(QPoint(mColNum, mRowNum), QPoint(mSurfaceWidth, mSurfaceHeight), mCustomCharsRaw);
}

void CharLcmView::setColRow(int col, int row)
{
    mColNum = col;
    mRowNum = row;
    reGenResoures();
    forceReDraw();
}

void CharLcmView::getColRow(int col, int row)
{
    col = mColNum;
    row = mRowNum;
}

void CharLcmView::resizeEvent(QResizeEvent *event)
{
    mSurfaceHeight = height();
    mSurfaceWidth = width();
    reGenResoures();
    forceReDraw();
}

void CharLcmView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    //    //设置QPainter的绘图区
    QRect rect(0, 0, width(), height());
    painter.setViewport(rect);
    painter.setRenderHint(QPainter::Antialiasing);

    mSurfaceHeight = height();
    mSurfaceWidth = width();

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    //painter.setRenderHint(QPainter::Antialiasing);
    brush.setColor(mLcdPanelColor);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    painter.fillRect(rect, brush);
    int dy = 0;
    QPointF postion = QPointF();

    for (int y = 0; y < mRowNum; y++)
    {
        for (int x = 0; x < mColNum; x++)
        {
            mFontGen.getActualCursor(x, y, &postion); // y*mColNum+x+32
            painter.drawPixmap(postion, mFontGen.getCharBitmap(mLcmChars[dy + x]));
        }
        dy += mColNum;
    }
}
