#ifndef UPDATER_H
#define UPDATER_H

#include <QtCore>
#include <QtGui>
#include <QtNetwork>
#include <QtXml>

namespace Ui {
class Updater;
}

class Updater : public QDialog
{
    Q_OBJECT
    
public:
    explicit Updater(QWidget *parent = 0);
    ~Updater();

public slots:

    // Fetch
    bool hasUpdate(const int version);
    bool fetchUpdate();
    void installUpdate();

private slots:

    // Download
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();
    void downloadError(QNetworkReply::NetworkError error);
    QTemporaryFile *downloadFile(QUrl url);

    // Event
    void closeEvent(QCloseEvent *);
    
private:
    struct UpdateFile
    {
        QString name;
        QTemporaryFile *file;
    };

    Ui::Updater *ui;
    QDomDocument *m_updateXml;
    QTemporaryFile *m_tempFile;
    QNetworkReply *m_reply;

    QList<UpdateFile> m_downloadedFiles;
    int m_filesToDownload;
    int m_currentFile;

    QNetworkAccessManager m_downloader;
    bool m_fileDownloaded;
    bool m_updateAborted;
};

#endif // UPDATER_H
