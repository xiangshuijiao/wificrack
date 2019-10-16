#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileSystemWatcher.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bash = new QProcess(this);

    ap_file = new FileSystemWatcher();
    connect(ap_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    ap_file->addWatchPath("./ap.txt");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_file_changed(QString path)
{
        QFileInfo file(path);
        QString strPath = file.absolutePath();
        QString strName = file.fileName();

        if(strName == QString::fromLocal8Bit("ap.txt"))
        {
                    QString displayString;
                    displayString.append("BSSID\t\tCH\tESSID\n");
                    QFile file("./ap.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open ap.txt error\n" << endl;
                   }

                    while(!file.atEnd())
                   {
                       QByteArray line = file.readLine();
                       QString str(line);
            //           qDebug()<< str;
                       QStringList list = str.simplified().split(" ");
                       if(list.length() < 3)
                                continue;
                       displayString.append(list.at(0));
                       displayString.append("\t");
                       displayString.append(list.at(1));
                       displayString.append("\t");
                       displayString.append(list.at(2));
                       displayString.append("\n");
//                       displayString.append(str);
                   }
                    ui->textEdit_AP->clear();
                    ui->textEdit_AP->setPlainText(displayString);
        }
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
