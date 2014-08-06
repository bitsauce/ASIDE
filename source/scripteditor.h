#ifndef SCRIPTEDITOR_H
#define SCRIPTEDITOR_H

#include <QFile>
#include <QMdiSubWindow>
#include <QDialog>
#include <QTextEdit>
#include <QCompleter>
#include <QStringListModel>
#include <QSyntaxHighlighter>
#include <QMdiArea>

#include "editorbase.h"

class QsciScintilla;

//-------------------------------------------
// ScriptGoTo
// The script go to line dialog
//-------------------------------------------

namespace Ui {
class ScriptSearch;
class ScriptReplace;
class ScriptGoTo;
}

class ScriptGoTo : public QDialog
{
    Q_OBJECT
public:
    explicit ScriptGoTo(QWidget *parent = 0);
    ~ScriptGoTo();

    void hideEvent(QHideEvent *);

private:
    Ui::ScriptGoTo *ui;

private slots:
    void gotoLine();

signals:
    void gotoLine(int line);
};

//-------------------------------------------
// ScriptFinder
// The script searching dialog
//-------------------------------------------

class ScriptSearch : public QDialog
{
    Q_OBJECT
public:
    explicit ScriptSearch(QWidget *parent = 0);
    ~ScriptSearch();

    // Search phrase
    void setSearchPharse(QString phrase);
    QString searchPhrase();

    // Find procedure
    void find(const QString &phrase, const bool forward);

private:
    Ui::ScriptSearch *ui;

    struct {
        QString phrase;
        int flags;
    } m_prevParam;

    void closeEvent(QCloseEvent *e);
    void showEvent(QShowEvent *e);

private slots:
    void searchForwards();
    void searchBackwards();
    void setNextDefault();
    void setPrevDefault();

signals:
    void findAll();
    void search(const QString &phrase, bool forward, bool regexp, bool matchCase, bool wholeWords);
    void next();
};

//-------------------------------------------
// ScriptFindReplace
// The script reaplce dialog
//-------------------------------------------

class ScriptReplace : public ScriptSearch
{
    Q_OBJECT
public:
    explicit ScriptReplace(QWidget *parent = 0);
    ~ScriptReplace();

    // Replace phrase
    void setReplacePharse(QString phrase);
    QString replacePhrase();

    bool replaceInAllFiles();

private:
    Ui::ScriptReplace *ui;

    struct {
        QString phrase;
        int flags;
    } m_prevParam;

private slots:
    void replaceSelection();

signals:
    void replace(const QString &phrase);
};

//-------------------------------------------
// ScriptEditor
// The default script editor
//-------------------------------------------

namespace Ui {
class ScriptEditor;
}

class ScriptEditor : public EditorBase
{
    Q_OBJECT
public:
    explicit ScriptEditor(QString path, QString title);
    ~ScriptEditor();

    static ScriptEditor *createFile(QString filePath);

    // Script text edit
    QsciScintilla *scriptTextEdit();

    //---------------------------------------
    // Debug
    //---------------------------------------

    // Breakpoints
    void scrollToLine(int line, int col = 0);
    int breakpointCount() const;
    bool isBreakpoint(const int line) const;
    void resizeBreakpoints(int at, int dt);

private:

    // Ui
    Ui::ScriptEditor *ui;

    // Text edit
    QsciScintilla *m_scriptTextEdit;

//    QLabel *posLabel;
//    QProgressBar *inteliBar;

    // Breakpoints
    QVector<bool> m_breakpoints;

public slots:

    // Editor
    void save();
    void load();
    void updatePositionLabel(int line, int col);
    void aboutToActivate();

    // Go to line
    void showScriptGoTo();
    void gotoLine(int line);

    // Search
    void showScriptSearch();
    void search(const QString &phrase, bool forward, bool regexp, bool matchCase, bool wholeWords);
    void findNext();
    void findAll();

    // Replace
    void showScriptReplace();
    void replaceSelection(const QString &phrase);
    void replaceAll();

    // Breakpoint
    void toggleBreakpoint(int, int line, Qt::KeyboardModifiers modifiers);
    void lineCountChanged(int start, int dt);
};

#endif // SCRIPTEDITOR_H
