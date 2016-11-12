#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filedownloader.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_cambiar_clicked();
    void loadImage();

private:
    Ui::MainWindow *ui;
    FileDownloader * m_pImgCtrl;
};

#endif // MAINWINDOW_H
