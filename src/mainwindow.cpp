#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnDownload_clicked()
{

    int n = 1000000000;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            n++;
            WebImage* obj = new WebImage(this);
            QString path = QApplication::applicationDirPath() + QString("/files/%1.jpg").arg(n);
            QString url = QString("https://img.yalayi.net/img/gallery/%1/z%2.jpg!pcimg").arg(100 + i).arg(j);
            bool ret = obj->download(url, path);
            delete obj;
            QString retStr = ret == true ? "成功" : "失败";
            ui->edtInfos->append("下载 " + url + " " + retStr);
            QApplication::processEvents();
            QThread::msleep(100);


        }


    }


}
