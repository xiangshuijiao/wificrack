#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileSystemWatcher.h"

#include "wpa2break.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    bash = new QProcess(this);

    // ap file watcher
    ap_file = new FileSystemWatcher();
    connect(ap_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    ap_file->addWatchPath("./ap.txt");

    // station file watcher
    station_file = new FileSystemWatcher();
    connect(station_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    station_file->addWatchPath("./station.txt");

    // show file watcher
    show_file = new FileSystemWatcher();
    connect(show_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    show_file->addWatchPath("./show.txt");

    // handshake file watcher
    handshake_file = new FileSystemWatcher();
    connect(handshake_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    handshake_file->addWatchPath("./handshake.txt");


    ui->lineEdit_interface->setPlaceholderText("INTERFACE NAME");
    ui->lineEdit_BSSID->setPlaceholderText("BSSID MAC");
    ui->lineEdit_CH->setPlaceholderText("CHANNEL");
    ui->lineEdit_dictionary->setPlaceholderText("DICTIONARY FILE PATH");
    ui->textEdit_AP->setPlaceholderText("AP INFORMATION：\n                  BSSID、CHANNEL、ESSID");
    ui->textEdit_STATION->setPlaceholderText("STATION INFORMATION：\n                 AP MAC、STATION MAC");

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

        // ap.txt changed
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
                       QStringList list = str.simplified().split(" ");
                       if(list.length() < 3)
                                continue;
                       displayString.append(list.at(0));
                       displayString.append("\t");
                       displayString.append(list.at(1));
                       displayString.append("\t");
                       displayString.append(list.at(2));
                       displayString.append("\n");
                   }
                    ui->textEdit_AP->clear();
                    ui->textEdit_AP->setPlainText(displayString);
        }

        // station.txt changed
        if(strName == QString::fromLocal8Bit("station.txt"))
        {
                    QString displayString;
                    displayString.append("AP MAC\t\tSTATION MAC\n");
                    QFile file("./station.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open station.txt error\n" << endl;
                   }
                    while(!file.atEnd())
                   {
                       QByteArray line = file.readLine();
                       QString str(line);
                       QStringList list = str.simplified().split(" ");
                       if(list.at(0) == "null")
                       {
                               displayString.append("(not associated)");
                               displayString.append("\t");
                       }
                       else
                       {
                               displayString.append(list.at(0));
                               displayString.append("\t");
                       }
                       displayString.append(list.at(1));
                       displayString.append("\n");
                   }
                    ui->textEdit_STATION->clear();
                    ui->textEdit_STATION->setPlainText(displayString);
        }

        // show.txt changed
        if(strName == QString::fromLocal8Bit("show.txt"))
        {
                    QString displayString;
                    QFile file("./show.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open show.txt error\n" << endl;
                   }
                    while(!file.atEnd())
                   {
                       QByteArray line = file.readLine();
                       QString str(line);
                       QStringList list = str.simplified().split(" ");

                       // must under { ui->setupUi(this); }
                       ui->statusBar->setSizeGripEnabled(false);
                       ui->statusBar->showMessage( "FRAME COUNT : " +  list.at(0));
                   }
        }

        // handshake.txt changed
        if(strName == QString::fromLocal8Bit("handshake.txt"))
        {
                    QString displayString;
                    QFile file("./handshake.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open handshake.txt error\n" << endl;
                   }
                    int count = 0;
                    while(!file.atEnd())
                   {

                       QByteArray line = file.readLine();
                       QString str(line);
                       str = str.simplified();
                       count++;
                       switch(count)
                       {
                                case 1:  displayString.append("破解需要的握手信息:\nSSID : " + str + "\n"); break;
                                case 2:  displayString.append("AP MAC : " + str + "\n"); break;
                                case 3:  displayString.append("STATION MAC : " + str + "\n"); break;
                                case 4:  displayString.append("AP Nonce : " + str + "\n"); break;
                                case 5:  displayString.append("STATION Nonce : " + str + "\n"); break;
                                case 6:  displayString.append("Step2 Data : " + str + "\n"); break;
                                case 7:  displayString.append("MIC : " + str + "\n"); break;
                                case 8:  displayString.append("被破解的AP:\nSSID : " + str); break;
                       }
                   }
                   QMessageBox::information(this, "抓取到破解密钥所需要的信息", displayString);
        }
}






void MainWindow::on_pushButton_scan_clicked()
{



        if(ui->pushButton_scan->text() == "scan")
        {
            if(ui->lineEdit_interface->text().toLocal8Bit() == "")
            {
                    QMessageBox::warning(this, "warning", "you must input the <INTERFACE NAME> before scanning!!! ");
                    return;
            }

            bash->start("bash");
            bash->waitForStarted();
            QString command("../airodump-ng  " + ui->lineEdit_interface->text().toLocal8Bit() );
            if (ui->lineEdit_BSSID->text().toLocal8Bit() != "")
            {
                    command.append(" --bssid " +  ui->lineEdit_BSSID->text().toLocal8Bit());
            }
            if (ui->lineEdit_CH->text().toLocal8Bit() != "")
            {
                    command.append(" -c " +  ui->lineEdit_CH->text().toLocal8Bit());
            }
            command.append("\n");
            qDebug() << command;
            QByteArray qba = command.toLatin1();
            qDebug() << qba;
            qDebug() << qba.data();
            bash->write(qba.data());

            ui->pushButton_crack->setEnabled(false);
            ui->lineEdit_BSSID->setEnabled(false);
            ui->lineEdit_CH->setEnabled(false);
            ui->lineEdit_interface->setEnabled(false);
            ui->lineEdit_dictionary->setEnabled(false);
            ui->pushButton_scan->setText("cancel");
        }
        else
        {
            bash->kill();

            ui->pushButton_crack->setEnabled(true);
            ui->lineEdit_BSSID->setEnabled(true);
            ui->lineEdit_CH->setEnabled(true);
            ui->lineEdit_interface->setEnabled(true);
            ui->lineEdit_dictionary->setEnabled(true);
            ui->pushButton_scan->setText("scan");
        }
}

void MainWindow::on_pushButton_crack_clicked()
{

    if(ui->pushButton_crack->text() == "crack")
    {
        if(ui->lineEdit_dictionary->text().toLocal8Bit() == "")
        {
                QMessageBox::warning(this, "warning", "you must input the <DICTIONARY FILE PATH> before cracking!!! ");
                return;
        }

        ui->pushButton_scan->setEnabled(false);
        ui->lineEdit_BSSID->setEnabled(false);
        ui->lineEdit_CH->setEnabled(false);
        ui->lineEdit_interface->setEnabled(false);
        ui->lineEdit_dictionary->setEnabled(false);
        ui->pushButton_crack->setEnabled(false);

        wpa2_handshake_t t_handshake;
        FILE* t_file=fopen("handshake.txt","r");
        char t_buffer[1024];
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.ssid);
        t_handshake.ssid_len=strlen((char*)t_handshake.ssid);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.ap_mac);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.sta_mac);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.ap_nonce);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.sta_nonce);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.step2_data);
        fgets(t_buffer,sizeof(t_buffer),t_file);
        hex2bin(t_buffer,t_handshake.step2_mic);
        fclose(t_file);
        wpa2break_init_mid_value(&t_handshake);



        FILE *fp;
        char str[256];
        long count = 0;
        if((fp=fopen(ui->lineEdit_dictionary->text().toLocal8Bit(), "r")) == NULL){
            qDebug() << "cannot open file " +  ui->lineEdit_dictionary->text().toLocal8Bit();
            return;
        }




        while(!feof(fp))
        {
            if(fgets(str, sizeof(str), fp) != NULL)
            {
                count++;
                ui->statusBar->setSizeGripEnabled(false);
                ui->statusBar->showMessage( "KEY COUNT : " +  QString::number(count));

                str[strlen(str)-2] = '\0';
                if (1 == wpa2break_is_password(&t_handshake,(uint8_t*)str, strlen(str)))
                {
                    QMessageBox::information(this,  "KEY FOUND", "KEY ： " + QString(QLatin1String(str)));
                    ui->pushButton_crack->setEnabled(true);
                    ui->lineEdit_BSSID->setEnabled(true);
                    ui->lineEdit_CH->setEnabled(true);
                    ui->lineEdit_interface->setEnabled(true);
                    ui->lineEdit_dictionary->setEnabled(true);
                    ui->pushButton_scan->setEnabled(true);
                    return;
                }
            }
        }
        QMessageBox::information(this,  "KEY NOT FOUND", "There is no valid password in the dictionary!!! ");


        ui->pushButton_crack->setEnabled(true);
        ui->lineEdit_BSSID->setEnabled(true);
        ui->lineEdit_CH->setEnabled(true);
        ui->lineEdit_interface->setEnabled(true);
        ui->lineEdit_dictionary->setEnabled(true);
        ui->pushButton_scan->setEnabled(true);


    }
}
