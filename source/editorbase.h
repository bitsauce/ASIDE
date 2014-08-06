#ifndef EDITORBASE_H
#define EDITORBASE_H

#include <QWidget>
#include <QMdiArea>

class EditorBase : public QWidget
{
    Q_OBJECT
    friend class Workspace;
public:
    explicit EditorBase(QString filePath, QString title);

    virtual void closeEvent(QCloseEvent *event);

    bool isModified() const;
    QString filePath() const;
    QMdiSubWindow *mdiWindow() const;

signals:

    void fileOpened(const QString &filePath);
    void fileSaved(const QString &filePath);
    void fileClosed(const QString &filePath);

public slots:

    virtual void load();
    virtual void save();
    virtual void setModified(bool modified);

private:

    QMdiSubWindow *m_mdiWindow;
    QString m_filePath;
    QString m_title;
    bool m_modified;
};

#endif // EDITORBASE_H
