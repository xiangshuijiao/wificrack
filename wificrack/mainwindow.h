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
    void slot_file_changed(QString path);

    void on_pushButton_scan_clicked();

    void on_pushButton_crack_clicked();

    void on_toolButton_directory_slecter_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *bash;
    QString AP_SSID;

    qint64 pos_key_file;

    FileSystemWatcher *ap_file;
    FileSystemWatcher *station_file;
    FileSystemWatcher *handshake_file;
    FileSystemWatcher *show_file;
    FileSystemWatcher *key_file;
    FileSystemWatcher *show2_file;
};

#endif // MAINWINDOW_H
