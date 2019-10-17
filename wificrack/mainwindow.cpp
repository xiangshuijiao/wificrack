#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileSystemWatcher.h"

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

    // key file watcher
    key_file = new FileSystemWatcher();
    connect(key_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    key_file->addWatchPath("./key.txt");

    // show2 file watcher
    show2_file = new FileSystemWatcher();
    connect(show2_file, SIGNAL(emit_signal_file_changed(QString)), this, SLOT(slot_file_changed(QString)));
    show2_file->addWatchPath("./show2.txt");

    ui->lineEdit_interface->setPlaceholderText("INTERFACE NAME");
    ui->lineEdit_BSSID->setPlaceholderText("BSSID MAC");
    ui->lineEdit_CH->setPlaceholderText("CHANNEL");
    ui->lineEdit_dictionary->setPlaceholderText("DICTIONARY FILE PATH");
    ui->textEdit_AP->setPlaceholderText("AP INFORMATION：\n                  BSSID、CHANNEL、ESSID");
    ui->textEdit_STATION->setPlaceholderText("STATION INFORMATION：\n                 AP MAC、STATION MAC");
    ui->textEdit_handshake->setPlaceholderText("HADNSHAKE INFORMATION：\n                 TWO MAC、TWO NONCE、MIC、STEP2 DATA、SSID");

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
                       ui->statusBar->showMessage( "FRAME NUMBER : " +  list.at(0));
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
                    QString temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
                    while(!file.atEnd())
                   {

                       QByteArray line = file.readLine();
                       QString str(line);
                       str = str.simplified();
                       count++;
                       switch(count)
                       {
                                case 1:  temp1 = "SSID :\t\t" + str + "\n"; break;
                                case 2:  temp2 = "AP MAC : \t\t" + str + "\n"; break;
                                case 3:  temp3 = "STATION MAC : \t" + str + "\n"; break;
                                case 4:  temp4 = "AP Nonce : \t\t" + str + "\n"; break;
                                case 5:  temp5 = "STATION Nonce : \t" + str + "\n"; break;
                                case 6:  temp6 = "Step2 Data : \t" + str; break;
                                case 7:  temp7 = "MIC : \t\t" + str + "\n"; break;
                                case 8:  temp8 = "被破解的AP:\t" + str + "\n";
                                              AP_SSID = str;break;
                                default: break;
                       }
                   }
                    displayString.append(temp8);
                    displayString.append(temp1);
                    displayString.append(temp2);
                    displayString.append(temp3);
                    displayString.append(temp4);
                    displayString.append(temp5);
                    displayString.append(temp7);
                    displayString.append(temp6);
                    ui->textEdit_handshake->clear();
                    ui->textEdit_handshake->setPlainText(displayString);
        }



        // show2.txt changed
        if(strName == QString::fromLocal8Bit("show2.txt"))
        {
                    QString displayString;
                    QFile file("./show2.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open show2.txt error\n" << endl;
                   }
                    while(!file.atEnd())
                   {

                       QByteArray line = file.readLine();
                       QString str(line);
                       str = str.simplified();
                       ui->statusBar->setSizeGripEnabled(false);
                       ui->statusBar->showMessage( "KEY NUMBER : " +  str);
                   }
        }

        // key.txt changed
        if(strName == QString::fromLocal8Bit("key.txt"))
        {
                    QString displayString;
                    QFile file("./key.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        qDebug() << "open key.txt error\n" << endl;
                   }
                    int count = 0;
                    while(!file.atEnd())
                   {
                         QFile file_temp("./handshake.txt");;
                         int count_temp;
                         QByteArray line_temp;


                       QByteArray line = file.readLine();
                       QString str(line);
                       str = str.simplified();
                       count++;
                       switch(count)
                       {
                                case 1:
                                                    // 从握手文件中获取AP_SSID

                                                   if (!file_temp.open(QIODevice::ReadOnly | QIODevice::Text))
                                                   {
                                                       qDebug() << "open handshake.txt error\n" << endl;
                                                  }
                                                   count_temp = 0;
                                                   while(!file_temp.atEnd())
                                                  {
                                                      line_temp = file_temp.readLine();
                                                      QString str_temp(line_temp);
                                                      str_temp = str_temp.simplified();
                                                      count_temp++;
                                                      switch(count_temp)
                                                      {
                                                               case 8:     AP_SSID = str_temp;break;
                                                               default: break;
                                                      }
                                                  }

                                                displayString.append("破解 [ "+ AP_SSID + " ] 使用了 [ " +  str   +" ] 条字典中的密码" + "\n"); break;
                                case 2:
                                              if ( str == "failed")
                                              {
                                                        displayString.append("字典中无有效密码\n");
                                                        count = 1000;  // not execute case 3;
                                              }
                                              else
                                              {
                                                        displayString.append("破解成功, 密码为 [ ");
                                              }
                                              break;

                                case 3:  displayString.append(str + " ]"); break;
                                default: break;
                       }
                   }
                   QMessageBox::information(this, "破解结果", displayString);
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


            ui->pushButton_crack->setEnabled(false);
            ui->lineEdit_BSSID->setEnabled(false);
            ui->lineEdit_CH->setEnabled(false);
            ui->lineEdit_interface->setEnabled(false);
            ui->lineEdit_dictionary->setEnabled(false);
            ui->pushButton_scan->setText("cancel");
            ui->textEdit_handshake->clear();

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

        bash->start("bash");
        bash->waitForStarted();
        QString command("../crack  " + ui->lineEdit_dictionary->text().toLocal8Bit() );
        command.append("\n");
        qDebug() << command;
        QByteArray qba = command.toLatin1();
        bash->write(qba.data());

        ui->pushButton_scan->setEnabled(false);
        ui->lineEdit_BSSID->setEnabled(false);
        ui->lineEdit_CH->setEnabled(false);
        ui->lineEdit_interface->setEnabled(false);
        ui->lineEdit_dictionary->setEnabled(false);
        ui->pushButton_crack->setText("cancel");
    }
    else
    {
        bash->kill();

        ui->pushButton_scan->setEnabled(true);
        ui->lineEdit_BSSID->setEnabled(true);
        ui->lineEdit_CH->setEnabled(true);
        ui->lineEdit_interface->setEnabled(true);
        ui->lineEdit_dictionary->setEnabled(true);
        ui->pushButton_crack->setText("crack");
    }

}
