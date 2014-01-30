#include "settings.h"
#include "ui_settings.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    // Load settings
    QStringList fileTypes = settings()->value("script_editor/file_types", "Script File;as").toStringList();
    foreach(QString fileType, fileTypes)
    {
        QStringList list = fileType.split(";");
        QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(ui->fileTypeTree, list);
        treeWidgetItem->setFlags(treeWidgetItem->flags() | Qt::ItemIsEditable);
        ui->fileTypeTree->insertTopLevelItem(0, treeWidgetItem);
    }

    // Load default application string
    ui->applicationLineEdit->setText(settings()->value("script_editor/default_application", "asrun.exe").toString());

    // Setup change detection
    foreach(QLineEdit* w, findChildren<QLineEdit*>())
        connect(w, SIGNAL(textChanged(QString)), this, SLOT(changed()));
    foreach(QTreeWidget* w, findChildren<QTreeWidget*>())
        connect(w, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(changed()));

    // Setup buttonry
    m_apply = ui->buttonBox->button(QDialogButtonBox::Apply);
    m_apply->setEnabled(false);
    connect(m_apply, SIGNAL(clicked()), this, SLOT(save()));
    QPushButton *ok = ui->buttonBox->button(QDialogButtonBox::Ok);
    connect(ok, SIGNAL(clicked()), this, SLOT(save()));
    m_changed = false;
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::save()
{
    if(!m_changed)
        return;

    // Save the settings
    QStringList fileTypes;
    for(int i = 0; i < ui->fileTypeTree->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *item = ui->fileTypeTree->topLevelItem(i);
        fileTypes << QString("%1;%2").arg(item->text(0)).arg(item->text(1));
    }
    settings()->setValue("script_editor/file_types", fileTypes);
    settings()->setValue("script_editor/default_application", ui->applicationLineEdit->text());

    m_apply->setEnabled(false);
}

void SettingsDialog::changed()
{
    m_apply->setEnabled(true);
    m_changed = true;
}

void SettingsDialog::addFileType()
{
    QStringList list;
    list << "";
    list << "";

    QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(ui->fileTypeTree, list);
    treeWidgetItem->setFlags(treeWidgetItem->flags() | Qt::ItemIsEditable);
    ui->fileTypeTree->insertTopLevelItem(0, treeWidgetItem);
    ui->fileTypeTree->setCurrentItem(treeWidgetItem);
    changed();
}

void SettingsDialog::removeFileType()
{
    delete ui->fileTypeTree->currentItem();
    changed();
}

Settings *g_settings;
Settings *settings()
{
    return g_settings;
}

Settings::Settings(QWidget *parent) :
    QSettings("MacroByte", "AngelScriptIDE", parent)
{
    Q_ASSERT(!g_settings);
    g_settings = this;
}

QStringList Settings::fileTypes()
{
    return value("script_editor/file_types", "Script File;as").toStringList();
}
