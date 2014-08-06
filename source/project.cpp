//     _    ____ ___ ____  _____
//    / \  / ___|_ _|  _ \| ____|
//   / _ \ \___ \| || | | |  _|
//  / ___ \ ___) | || |_| | |___
// /_/   \_\____/___|____/|_____|
// Originally written by Marcus Loo Vergara (aka. Bitsauce)
// 2011-2014 (C)

#include "ui_projectdialog.h"
#include "ui_newprojectdialog.h"

#include "project.h"
#include "workspace.h"
#include "settings.h"

#define NUM_RECENT_PROJECTS 10

//------------------------------------------------
// ProjectDialog
// The main project dialog
//------------------------------------------------

bool Project::s_loaded = false;
QString Project::s_directory = "";
QString Project::s_name = "";
QSettings *Project::s_config = 0;

bool Project::isLoaded()
{
    return s_loaded;
}

QString Project::getDirectory()
{
    return s_directory;
}

QString Project::getName()
{
    return s_name;
}

QSettings *Project::getConfig()
{
    return s_config;
}

int Project::createProject(QString name, QString path)
{
    // Gete project file path
    QString filePath = path + "/" + name + ".x2d";

    // Make sure project dosen't already exist
    if(QFile::exists(filePath))
        return PROJECT_ALREADY_EXSISTS;

    // Open file
    QSettings newConfig(filePath, QSettings::IniFormat);
    if(!newConfig.isWritable())
        return PROJECT_UNABLE_TO_WRITE;

    // Write project info
    newConfig.setValue("project/name", name);

    // Create project files
    QFile mainFile(path + "/main.as");
    if(!mainFile.open(QFile::ReadWrite | QFile::Text))
        return PROJECT_UNABLE_TO_WRITE;

    // Create empty file
    QTextStream stream(&mainFile);
    stream << "\0";
    mainFile.close();

    // Success
    return 0;
}

int Project::loadProject(const QString &path)
{
    // Load project config file
    QSettings *config = new QSettings(path, QSettings::IniFormat);
    if(config->status() != QSettings::NoError) {
        return PROJECT_UNABLE_TO_READ;
    }
    s_config = config;

    // Set project path
    s_directory = QFileInfo(path).absolutePath();
    if(s_directory[s_directory.size()-1] != '/') {
        s_directory += "/";
    }

    s_name = s_config->value("project/name", "").toString();

    // Add project to recent list
    QString name = s_name;
    QString currPath, currName,
            prevPath = path, prevName = name;
    for(int i = 0; i < NUM_RECENT_PROJECTS; i++)
    {
        // Get project at position
        currPath = settings()->value("recent_projects/" + QString::number(i) + "/path", "").toString();
        currName = settings()->value("recent_projects/" + QString::number(i) + "/name", "").toString();

        // Until found
        if(prevPath.isEmpty() && prevName.isEmpty())
            break;
        if(currPath == path && currName == name)
        {
            settings()->setValue("recent_projects/" + QString::number(i) + "/path", prevPath);
            settings()->setValue("recent_projects/" + QString::number(i) + "/name", prevName);
            break;
        }

        // Swap position
        settings()->setValue("recent_projects/" + QString::number(i) + "/path", prevPath);
        settings()->setValue("recent_projects/" + QString::number(i) + "/name", prevName);
        prevPath = currPath;
        prevName = currName;
    }
    s_loaded = true;

    // Success
    return 0;
}

void Project::saveProject()
{
}

void Project::closeProject()
{
    s_name.clear();
    s_directory.clear();
    if(s_config)
    {
        s_config->deleteLater();
        s_config = 0;
    }
    s_loaded = false;
}

//------------------------------------------------
// ProjectDialog
// The main project dialog
//------------------------------------------------

ProjectDialog::ProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectDialog)
{
    // Setup ui
    ui->setupUi(this);

    // Signals
    connect(ui->newProjectButton, SIGNAL(clicked()), this, SIGNAL(createProject()));
    connect(ui->openProjectButton, SIGNAL(clicked()), this, SIGNAL(openProject()));

    // Setup recent list
    m_listModel = new QStringListModel(this);
    ui->recentList->setModel(m_listModel);
    ui->recentList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->recentList->setItemDelegate(new ProjectItemDelegate(ui->recentList, this));
    m_listModel->setStringList(QStringList());
    QTimer::singleShot(100, this, SLOT(repaintList()));

    // Set window flags to splash widget
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
}

ProjectDialog::~ProjectDialog()
{
    delete ui;
}

void ProjectDialog::showEvent(QShowEvent *e)
{
    setupList();
    QDialog::showEvent(e);
}

void ProjectDialog::removeListItem(int idx)
{
    // Remove item
    QString currPath, currName;
    for(int i = idx+1; i < NUM_RECENT_PROJECTS; i++)
    {
        // Get project at position
        currPath = settings()->value("recent_projects/" + QString::number(i) + "/path", "").toString();
        currName = settings()->value("recent_projects/" + QString::number(i) + "/name", "").toString();

        // Move position
        settings()->setValue("recent_projects/" + QString::number(i-1) + "/path", currPath);
        settings()->setValue("recent_projects/" + QString::number(i-1) + "/name", currName);

        // Until end
        if(currPath.isEmpty() && currName.isEmpty())
            break;
    }

    // Re-setup list
    setupList();
}

void ProjectDialog::repaintList()
{
    ui->recentList->repaint();
    QTimer::singleShot(100, this, SLOT(repaintList()));
}

void ProjectDialog::setupList()
{
    // Setup list
    QStringList list;
    for(int i = 0; i < 5; i++)
    {
        QString name = settings()->value("recent_projects/" + QString::number(i) + "/name", "").toString();
        if(name.isEmpty()) break;
        list << name;
    }

    // Set list
    m_listModel->setStringList(list);
}

void ProjectDialog::clearList()
{
    // Clear list
    m_listModel->setStringList(QStringList());

    // Clear settings
    for(int i = 0; i < NUM_RECENT_PROJECTS; i++)
    {
        settings()->setValue(QString("recent_projects/%1/name").arg(i), "");
        settings()->setValue(QString("recent_projects/%1/path").arg(i), "");
    }
}

void ProjectDialog::clickList(QModelIndex idx)
{
    // Fetch project info
    int projectIdx = idx.row();
    QString path = settings()->value(QString("recent_projects/%1/path").arg(projectIdx)).toString();
    QString name = settings()->value(QString("recent_projects/%1/name").arg(projectIdx)).toString();

    // Check if project is valid
    if(path.isEmpty() || name.isEmpty() ||
            !QFile::exists(path))
    {
        int r = QMessageBox::question(this, "Project not found", "The selected project was not found. "
                                      "Would you like to to remove it from the list?",
                                      QMessageBox::Yes, QMessageBox::No);
        // Remove item
        if(r == QMessageBox::Yes)
            removeListItem(projectIdx);
        return;
    }

    // Check if the remove button was pressed
    QPoint pos = ui->recentList->mapFromGlobal(QCursor::pos());
    QRect rect(360, projectIdx*20+2, 16, 16);
    if(rect.contains(pos))
    {
        // Remove item
        removeListItem(projectIdx);
        return;
    }

    // Load project
    emit loadProject(path);
}

//------------------------------------------------
// NewProjectDialog
// The new project dialog
//------------------------------------------------

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    // Setup ui
    ui->setupUi(this);

    // Set defaults
    ui->projectNameEdit->setText("ASProject");
    ui->projectPathEdit->setText(QDir::homePath());

    // Remove help button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

QString NewProjectDialog::projectName()
{
    return ui->projectNameEdit->text();
}

QString NewProjectDialog::projectPath()
{
    return ui->projectPathEdit->text();
}

void NewProjectDialog::browseProjectPath()
{
    // Get and set path
    QString dir = ui->projectPathEdit->text();
    if(dir.isEmpty()) dir = QDir::currentPath();
    QString path = QFileDialog::getExistingDirectory(0, tr("Select Path"), dir);
    if(!path.isEmpty())
        ui->projectPathEdit->setText(path.replace("\\", "/"));
}

void NewProjectDialog::acceptDialog()
{
    // Check the fields
    if(ui->projectPathEdit->text().isEmpty() ||
            ui->projectNameEdit->text().isEmpty())
    {
        QMessageBox::information(this,
                                 tr("New Project"),
                                 tr("Please fill in all the required fields to continue."),
                                 QMessageBox::Ok);
        return;
    }

    // Create new project
    accept();
}

void NewProjectDialog::cancelDialog()
{
    reject();
}
