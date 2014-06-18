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
#include <QDebug>
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

private:
    Ui::ScriptSearch *ui;

private:
    void closeEvent(QCloseEvent *e);
    void showEvent(QShowEvent *e);

private slots:
    void setNextDefault();
    void setPrevDefault();

signals:
    void findNext();
    void findPrev();
    void findAll();
};

//-------------------------------------------
// ScriptFindReplace
// The script reaplce dialog
//-------------------------------------------

class ScriptReplace : public QDialog
{
    Q_OBJECT
public:
    explicit ScriptReplace(QWidget *parent = 0);
    ~ScriptReplace();

    // Search phrase
    void setSearchPharse(QString phrase);
    QString searchPhrase();

    // Replace phrase
    void setReplacePharse(QString phrase);
    QString replacePhrase();

    // Check boxes
    bool replaceInAllFiles();

private:
    Ui::ScriptReplace *ui;

private:
    void closeEvent(QCloseEvent *e);
    void showEvent(QShowEvent *e);

private slots:
    void setNextDefault();
    void setPrevDefault();

signals:
    void findNext();
    void findPrev();
    void replace();
    void replaceAll();
};

//-------------------------------------------
// ScriptEditor
// The default script editor
//-------------------------------------------

namespace Ui {
class ScriptEditor;
}

class ScriptEditor : public QWidget
{
    Q_OBJECT
public:
    explicit ScriptEditor(QString filePath, QString defaultTitle, QWidget *parent);
    ~ScriptEditor();

    static void loadProject(QString projectPath, QString projectName);

    static ScriptEditor *createFile(QString filePath);
    static ScriptEditor *openFile(QString filePath);

    // Script text edit
    QsciScintilla *scriptTextEdit();

    // Script file
    void loadFile(const QString &filePath);
    QString filePath() const;
    QMdiSubWindow *mdiWindow() const;
    bool isSaved() const;

    // Events
    void closeEvent(QCloseEvent *event);

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

    // Script file
    QString m_filePath;
    QString m_defaultTitle;
    QMdiSubWindow *m_mdiWindow;

//    QLabel *posLabel;
//    QProgressBar *inteliBar;

    // Breakpoints
    QVector<bool> m_breakpoints;

public slots:

    // Editor
    void save();
    void resetSaveState();
    void updateSaveState(bool modified);
    void textChanged();
    void updatePositionLabel(int line, int col);
    void aboutToActivate();

    // Go to line
    void showScriptGoTo();
    void gotoLine(int line);

    // Search
    void showScriptSearch();
    void findNext();
    void findPrev();
    void findAll();

    // Replace
    void showScriptReplace();
    void replaceSelection();
    void replaceAll();

    // Breakpoint
    void toggleBreakpoint(int, int line, Qt::KeyboardModifiers modifiers);
    void lineCountChanged(int start, int dt);

signals:
    void fileOpened(const QString &filePath);
    void fileSaved(const QString &filePath);
    void fileClosed(const QString &filePath);
};


//-------------------------------------------------------------
// AngelScriptPraser: The AngelScript syntax highlighter
// and praser
//-------------------------------------------------------------

class AngelScriptPraser : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    AngelScriptPraser(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

    struct Comment
    {
        int start;
        int end;
        bool contains(int idx)
        {
            return idx >= start && idx <= end;
        }
    };

private:

    // Include
    QTextCharFormat includeFormat;
    QRegExp includeExpression;

    // Datatypes
    QTextCharFormat datatypeFormat;
    QVector<QRegExp> datatypeExpressions;

    // Statements
    QTextCharFormat statementFormat;
    QVector<QRegExp> statementExpressions;

    // Comments
    QTextCharFormat commentFormat;
    QMultiMap<int, Comment> comments;

    // Single line comment
    QRegExp singleLineExpression;

    // Multi line comment
    QRegExp multiLineStartExpression;
    QRegExp multiLineEndExpression;

    // Quotation
    QTextCharFormat quotationFormat;
    QRegExp quotationExpression;

    // Function
    QTextCharFormat functionFormat;
};


#endif // SCRIPTEDITOR_H
