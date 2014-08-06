#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class Settings;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

public slots:

    // Save dialog to settings
    void save();

    // Dialog changed slot
    void changed();

    // File types
    void addFileType();
    void removeFileType();

    // Browse default application
    void browseDefaultApplication();
    
private:
    Ui::Settings *ui;

private:
    QPushButton *m_apply;
    bool m_changed;
};

class Settings : public QSettings
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);

    QStringList fileTypes();
};
extern Settings *settings();

#endif // SETTINGS_H
