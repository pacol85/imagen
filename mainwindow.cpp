#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <filedownloader.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //m_netwManager = new QNetworkAccessManager(this);
    //connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwManagerFinished(QNetworkReply*)));
    QPixmap pix("C:/Users/USUARIO/Dropbox/SVN/DESARROLLO/php/comercial/public/images/logoClean.png");
    ui->lbl_image->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_action_Download_triggered()
{
    QUrl url("http://farm5.static.flickr.com/4101/4798839454_725882374d_b.jpg");
    QNetworkRequest request(url);
    m_netwManager->get(request);
}

void MainWindow::slot_netwManagerFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QVariant attribute = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (attribute.isValid()) {
        QUrl url = attribute.toUrl();
        qDebug() << "must go to:" << url;
        return;
    }
    qDebug() << "ContentType:" << reply->header(QNetworkRequest::ContentTypeHeader).toString();
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    ui->m_lblImage->setPixmap(pixmap);
}
*/

void MainWindow::on_btn_cambiar_clicked()
{
    //QPixmap pix2("C:/Users/USUARIO/Pictures/taza001.png");
    //QPixmap pix2("http://farm5.static.flickr.com/4101/4798839454_725882374d_b.jpg");
    //ui->lbl_image->setPixmap(pix2);
    //QPixmap buttonImage;
    //buttonImage.loadFromData(m_pImgCtrl->downloadedData());
    //ui->lbl_image->setPixmap(buttonImage);

    QUrl imageUrl("http://farm5.static.flickr.com/4101/4798839454_725882374d_b.jpg");

    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void MainWindow::loadImage()
{
 QPixmap buttonImage;
 buttonImage.loadFromData(m_pImgCtrl->downloadedData());
 ui->lbl_image->setPixmap(buttonImage);
}
