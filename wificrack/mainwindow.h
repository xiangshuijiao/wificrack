#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include "FileSystemWatcher.h"
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
    void ap_file_changed(QString displayString);
    void station_file_changed(QString displayString);
    void handshake_file_changed(QString displayString);

    void on_pushButton_scan_clicked();



private:
    Ui::MainWindow *ui;
    QProcess *bash;

    FileSystemWatcher *ap_file;
    FileSystemWatcher *station_file;
    FileSystemWatcher *handshake_file;
};

#endif // MAINWINDOW_H
