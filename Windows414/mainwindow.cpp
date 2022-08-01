#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <QDebug>
#include <string>
#include <vector>
#include <QUrl>
#include <QDesktopServices>
#include <iostream>
//#include <QPoint>
//using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = ui->lineEdit->text();
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap(fileName));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}


void MainWindow::on_pushButton_clicked()
{
    std::string info;
    std::vector<cv::Point> points;
    cv::Mat correct_img;
    cv::Mat src_img = cv::imread(ui->lineEdit->text().toStdString());
    if(src_img.empty())
    {
        qDebug()<<"error! open src_img failed";
        return;
    }
//    cv::imshow("123",src_img);
    cv::QRCodeDetector detector;
    info = detector.detectAndDecode(src_img,points,correct_img);
    std::cout<<info;
    QDesktopServices::openUrl(QUrl(QString::fromStdString(info)));
//    qDebug()<<"info: "<<QString::fromStdString(info);
//    cv::imshow("1",correct_img);
    //   D:\Qt\Windows414\Jay_4.jpg
    //   D:\Qt\Windows414\1.png
}

