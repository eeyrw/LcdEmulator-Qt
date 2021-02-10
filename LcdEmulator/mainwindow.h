#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnSetBackColor_clicked();
    void on_btnSetGridColor_clicked();
    void on_btnSetPixelColor_clicked();

    void on_btnFullScreen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
