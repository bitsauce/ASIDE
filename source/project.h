#ifndef PROJECT_H
#define PROJECT_H

#include <QWidget>
#include <QDialog>
#include <QDir>
#include <QSettings>
#include <QStringListModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QItemDelegate>
#include <QPainter>
#include <QListView>
#include <QTimer>
#include <QApplication>
#include <QPixmap>
#include <QIcon>

class ProjectDialog;
class NewProjectDialog;
namespace Ui {
class ProjectDialog;
class NewProjectDialog;
}

// Project defines
#define PROJECT_UNABLE_TO_READ -1
#define PROJECT_UNABLE_TO_WRITE -2
#define PROJECT_ALREADY_EXSISTS -3

// Contains project information
class Project : public QObject
{
    Q_OBJECT
    friend class ProjectDialog;
    friend class MainWindow;
public:
    static QString getProjectDir();
    static QString getProjectName();
    static QSettings *getProjectConfig();

private:
    static int createProject(QString name, QString path);
    static int loadProject(QString path);
    static void saveProject();
    static void closeProject();

    static QString s_projectDir;
    static QString s_projectName;
    static QSettings *s_projectConfig;
};

// The recent list delegate
class ProjectItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ProjectItemDelegate(QListView *list, QObject *parent = 0) :
        QItemDelegate(parent),
        m_list(list)
    {
        // Load x pixmaps
        QIcon icon(":/projectdialog/icons/remove_x.png");
        m_xActive = icon.pixmap(16, QIcon::Normal);
        m_xHover = icon.pixmap(16, QIcon::Selected);
        m_xPressed = icon.pixmap(16, QIcon::Disabled);
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        // Change colors
        if(option.state & QStyle::State_MouseOver)
        {
            // Hover
            painter->fillRect(option.rect, QColor(125, 175, 255, 127));
        }
        else if(option.state & QStyle::State_Selected)
        {
            // Selected
            painter->fillRect(option.rect, QColor(224, 255, 255, 255));
        }

        // Draw item
        QItemDelegate::paint(painter, option, index);

        // Draw remove x
        if(option.state & QStyle::State_MouseOver)
        {
            QRect rect(360, option.rect.y()+2, 16, 16);
            if(rect.contains(m_list->mapFromGlobal(QCursor::pos())))
            {
                if(QApplication::mouseButtons() == Qt::LeftButton)
                    painter->drawPixmap(rect, m_xPressed);
                else
                    painter->drawPixmap(rect, m_xHover);
            }
            else
                painter->drawPixmap(rect, m_xActive);
        }
    }

private:
    QListView *m_list;
    QPixmap m_xActive;
    QPixmap m_xHover;
    QPixmap m_xPressed;
};

// The main project dialog
class ProjectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ProjectDialog(QWidget *parent = 0);
    ~ProjectDialog();

    void showEvent(QShowEvent *e);

private:
    Ui::ProjectDialog *ui;
    QStringListModel *m_listModel;

private slots:
    void removeListItem(int idx);
    void repaintList();
    void setupList();
    void clearList();
    void clickList(QModelIndex idx);

signals:
    void newProject();
    void openProject();
    void loadProject(QString path);
};

// The new project dialog
class NewProjectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

    QString projectName();
    QString projectPath();
private:
    Ui::NewProjectDialog *ui;

private slots:
    void browseProjectPath();
    void acceptDialog();
    void cancelDialog();
};

#endif // PROJECT_H
