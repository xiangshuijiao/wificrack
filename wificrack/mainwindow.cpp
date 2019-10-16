#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileSystemWatcher.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bash = new QProcess(this);

    ap_file = new FileSystemWatcher();
    connect(ap_file, SIGNAL(emit_signal_ap_data_changed(QString)), this, SLOT(ap_file_changed(QString)));
    ap_file->addWatchPath("./ap.txt");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ap_file_changed(QString displayString)
{
    qDebug() << "SLOT   ap_file_changed" << endl;
    ui->textEdit_AP->clear();
    ui->textEdit_AP->setPlainText(displayString);
}

void MainWindow::station_file_changed(QString displayString)
{

}

void MainWindow::handshake_file_changed(QString displayString)
{

}



void MainWindow::on_pushButton_scan_clicked()
{



        bash->start("bash");
        bash->waitForStarted();


        if(ui->pushButton_scan->text() == "scan")
        {
            bash->write("./airodump-ng  " + ui->lineEdit_interface->text().toLocal8Bit()  + "\n");

            ui->pushButton_crack->setEnabled(false);
            ui->lineEdit_BSSID->setEnabled(false);
            ui->lineEdit_CH->setEnabled(false);
            ui->lineEdit_interface->setEnabled(false);
            ui->pushButton_scan->setText("cancel");
        }
        else
        {
            bash->kill();

            ui->pushButton_crack->setEnabled(true);
            ui->lineEdit_BSSID->setEnabled(true);
            ui->lineEdit_CH->setEnabled(true);
            ui->lineEdit_interface->setEnabled(true);
            ui->pushButton_scan->setText("scan");
        }

}
