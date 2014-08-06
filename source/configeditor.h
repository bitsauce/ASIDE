#ifndef CONFIGEDITOR_H
#define CONFIGEDITOR_H

#include "editorbase.h"

#include <QString>

namespace Ui {
class ConfigEditor;
}

//
class ConfigEditor : public EditorBase
{
    Q_OBJECT
public:
    explicit ConfigEditor(QString path, QString title);
    ~ConfigEditor();

private:
    Ui::ConfigEditor *ui;

public slots:

    void save();

private slots:

    void formChanged(QString);
    void done();
    void cancel();
};

#endif // CONFIGEDITOR_H
