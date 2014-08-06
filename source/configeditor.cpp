#include "configeditor.h"
#include "project.h"

#include "ui_configeditor.h"

ConfigEditor::ConfigEditor(QString path, QString title) :
    EditorBase(path, title),
    ui(new Ui::ConfigEditor)
{
    ui->setupUi(this);

    QSettings *config = Project::getConfig();
    ui->nameLineEdit->setText(config->value("project/name", "").toString());
    ui->programLineEdit->setText(config->value("project/program", "").toString());

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(done()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancel()));

    connect(ui->nameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(formChanged(QString)));
    connect(ui->programLineEdit, SIGNAL(textChanged(QString)), this, SLOT(formChanged(QString)));

    setModified(false);
}

ConfigEditor::~ConfigEditor()
{
    delete ui;
}

void ConfigEditor::save()
{
    QSettings *config = Project::getConfig();
    config->setValue("project/name", ui->nameLineEdit->text());
    config->setValue("project/program", ui->programLineEdit->text());
    EditorBase::save();
}

void ConfigEditor::formChanged(QString)
{
    setModified(true);
}

void ConfigEditor::done()
{
    save();
    close();
}

void ConfigEditor::cancel()
{
    setModified(false);
    close();
}
