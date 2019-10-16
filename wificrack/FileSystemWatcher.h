#ifndef FILESYSTEMWATCHER_H
#define FILESYSTEMWATCHER_H

#include <QObject>
#include <QMap>
#include <QFileSystemWatcher>

class FileSystemWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileSystemWatcher(QObject *parent = 0);
    ~FileSystemWatcher();

    void addWatchPath(QString path);

signals:
    void emit_signal_file_changed(QString path);


public slots:
    void directoryUpdated(const QString &path);  // 目录更新时调用，path是监控的路径
    void fileUpdated(const QString &path);   // 文件被修改时调用，path是监控的路径

private:
    FileSystemWatcher *m_pInstance;
    QFileSystemWatcher *m_pSystemWatcher;  // QFileSystemWatcher变量
    QMap<QString, QStringList> m_currentContentsMap; // 当前每个监控的内容目录列表
};

#endif // FILESYSTEMWATCHER_H
