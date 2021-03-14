#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./api/http/webimage.h"
#include "./api/http/synchttpobject.h"
#include "./api/http/htmlinfo.h"
#include <QThread>
#include <QDir>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnDownload_clicked();

    void on_btnDownloadHeiguang_clicked();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
