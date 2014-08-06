#include "editorbase.h"
#include "workspace.h"
#include "settings.h"

EditorBase::EditorBase(QString filePath, QString title) :
    QWidget(workspace()),
    m_filePath(filePath),
    m_title(title),
    m_modified(true)
{
    m_mdiWindow = workspace()->createMdiWindow(this);
    m_mdiWindow->setWindowTitle(title);
    m_mdiWindow->resize(settings()->value("script_editor/subwindow_size", QSize(540, 400)).toSize());
    m_mdiWindow->show();
}

bool EditorBase::isModified() const
{
    return m_modified;
}

QString EditorBase::filePath() const
{
    return m_filePath;
}

QMdiSubWindow *EditorBase::mdiWindow() const
{
    return m_mdiWindow;
}

void EditorBase::load()
{
    setModified(false);
    emit fileOpened(m_filePath);
}

void EditorBase::save()
{
    setModified(false);
    emit fileSaved(m_filePath);
}

void EditorBase::setModified(bool modified)
{
    if(modified)
    {
        m_mdiWindow->setWindowTitle(m_title + "*");
    }else{
        m_mdiWindow->setWindowTitle(m_title);
    }
    m_modified = modified;
}


void EditorBase::closeEvent(QCloseEvent *event)
{
    // Check if we need to save
    if(m_modified)
    {
        // Display the dialog
        int r = QMessageBox::question(this, "Save", "Do you want to save the changes?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(r == QMessageBox::Yes)
        {
            // Yes, save here
            save();
        } else if(r == QMessageBox::Cancel) {
            // Cancel the close operation
            event->ignore();
            return;
        }

        // No need for saving
        setModified(false);
    }
    m_mdiWindow->close();
    emit fileClosed(m_filePath);
}
