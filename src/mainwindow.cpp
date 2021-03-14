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

void MainWindow::on_btnDownloadHeiguang_clicked()
{
    //8000 到100000
    for (int i = 23222; i <= 100000; i++)
    {
        ui->edtInfos->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        QString url = QString("https://tu.heiguang.com/works/show_%1.html").arg(i);
        SyncHttpObject* web = new SyncHttpObject(this);
        QByteArray data;
        int ret = web->getHtmlData(url, data);
        if (ret == 200)
        {
            QString html = data;
            QString title = getTitle(html).replace("|", " ");
            ui->edtInfos->append(url);
            ui->edtInfos->append(title);
            if (hasKeywordInHtml(title, "儿童摄影"))
            {

                QStringList urls;
                getImageSrc(html, urls);
                int n = 0;
                for (int j = 0; j < urls.count(); j++)
                {
                    if (urls[j].endsWith("!c") == false)
                    {
                        continue;
                    }

                    QDir dir;
                    QString folderPath = QString("f:/files/%1_%2").arg(i).arg(title);
                    dir.mkpath(folderPath);
                    QString path = folderPath + QString("/%1.jpg").arg(10000 + j);
                    WebImage* obj = new WebImage(this);
                    bool ret = obj->download(urls[j], path);
                    delete obj;
                    QString retStr = ret == true ? "成功" : "失败";
                    ui->edtInfos->append("下载 " + urls[j] + " " + retStr);
                    QApplication::processEvents();
                    QThread::msleep(50);
                    n++;


                }
            }



            QThread::msleep(100);
            QApplication::processEvents();
        }
        else
        {
            ui->edtInfos->append(url + "失败" + QString(" 错误代码:%1").arg(ret));
            QApplication::processEvents();
            if (ret != 404)
            {
                QThread::msleep(5000);
            }
            else
            {
                QThread::msleep(100);
            }

        }
        delete  web;
    }

}
