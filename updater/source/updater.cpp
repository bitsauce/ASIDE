#include "updater.h"
#include "ui_updater.h"

Updater::Updater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updater),
    m_tempFile(NULL),
    m_reply(NULL),
    m_updateXml(NULL),
    m_fileDownloaded(false),
    m_updateAborted(false),
    m_filesToDownload(1),
    m_currentFile(0)
{
    // Setup ui
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    // Download update info
    QTemporaryFile *tempFile = downloadFile(QUrl("http://mixedgraphics.net/editor/update.xml"));
    if(tempFile->open())
    {
        // Setup xml file
        m_updateXml = new QDomDocument;
        if(!m_updateXml->setContent(tempFile))
            m_updateXml = NULL;
    }
}

Updater::~Updater()
{
    delete m_updateXml;
    delete ui;
}

QString nodeValue(QDomNode node)
{
    QDomNode child = node.childNodes().at(0);
    if(child.isText())
        return child.nodeValue();
    return "";
}

bool Updater::hasUpdate(const int version)
{
    // Sanity check
    if(!m_updateXml)
        return false;

    // Read version and check for update
    QDomNode vernode = m_updateXml->firstChildElement("update").elementsByTagName("version").at(0);
    int updateVersion = nodeValue(vernode).toInt();
    if(updateVersion > version)
        return true;
    return false;
}

bool Updater::fetchUpdate()
{
    QDomNode changenode = m_updateXml->firstChildElement("update").elementsByTagName("changed").at(0);
    QDomNodeList childNodes = changenode.childNodes();
    QTemporaryFile *tempFile;
    m_filesToDownload = childNodes.count();
    m_currentFile = 0;
    for(int i = 0; i < childNodes.count(); i++)
    {
        // Check for return
        if(m_updateAborted)
            return false;

        // Get url
        QString url = nodeValue(childNodes.at(i));
        if(url.isEmpty())
            continue;

        // Download file
        tempFile = downloadFile(QUrl(url));
        UpdateFile file = { url.split('/').last(), tempFile };
        m_downloadedFiles.push_back(file);
        m_currentFile++;
    }
    return true;
}

void Updater::installUpdate()
{
    // Set label
    ui->progressLabel->setText("Installing");

    // Wait for close
    QFile editor(QCoreApplication::applicationDirPath() + "/Aurorax2D_Editor.exe", this);
    int retry = QMessageBox::Retry;
    while(!editor.open(QIODevice::ReadWrite))
    {
        retry = QMessageBox::warning(this, "Installing", "Please close the editor in order to install the update",
                                     QMessageBox::Retry, QMessageBox::Cancel);
        if(retry == QMessageBox::Cancel)
            break;
    }
    editor.close();

    // Cancel install
    if(retry == QMessageBox::Cancel)
        return;

    // Write new files
    ui->cancelButton->setEnabled(false);
    for(int i = 0; i < m_downloadedFiles.size(); i++)
    {
        UpdateFile *updateFile = &m_downloadedFiles[i];
        QString fileName = QCoreApplication::applicationDirPath() + "/" + updateFile->name;
        if(QFile::exists(fileName))
            QFile::remove(fileName);
        updateFile->file->copy(fileName);
    }

    // Restart editor
    QProcess *editorProcess = new QProcess(this);

    // Set open file argument
    QStringList args;

    // Start process
    editorProcess->startDetached(editor.fileName(), args);

    // Close updater
    close();
}

void Updater::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesReceived);
}

void Updater::downloadFinished()
{
    m_tempFile->close();
    m_fileDownloaded = true;
}

void Updater::downloadReadyRead()
{
    m_tempFile->write(m_reply->readAll());
}

void Updater::downloadError(QNetworkReply::NetworkError)
{
    // Perform silent close
    close();
}

QTemporaryFile *Updater::downloadFile(QUrl url)
{
    // Create temp file
    m_tempFile = new QTemporaryFile(this);
    if(!m_tempFile->open())
        return NULL;

    m_fileDownloaded = false;

    // Download file
    m_reply = m_downloader.get(QNetworkRequest(url));
    connect(m_reply, SIGNAL(finished()), this, SLOT(downloadFinished()));
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
    connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));

    ui->progressLabel->setText("Downloading: " + url.path().split('/').last() + " (" +
                               QString::number(m_currentFile) + "/" + QString::number(m_filesToDownload) + ")");

    // Receive file
    while(!m_fileDownloaded && !m_updateAborted)
        QCoreApplication::processEvents();

    return m_tempFile;
}

void Updater::closeEvent(QCloseEvent *e)
{
    if(m_reply)
        m_reply->close();
    if(m_tempFile)
        m_tempFile->close();
    m_updateAborted = true;
    QDialog::closeEvent(e);
}
