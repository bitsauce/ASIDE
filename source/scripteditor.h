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

//------------------------------------------------
// ScriptIntel
// The script text editor widget
//------------------------------------------------

class ScriptEditor;

//------------------------------------------------
// ScriptTextEdit
// The script text editor widget
//------------------------------------------------

class LineNumberArea;
class ScriptTextEdit : public QTextEdit
{
    Q_OBJECT
    friend class LineNumberArea;
public:
    explicit ScriptTextEdit(ScriptEditor *scriptEdit);

    // Convienience functions
    QString textUnderCursor() const;
    int tabCountAt(int pos);
    int findString(const QRegExp str, int pos, QTextDocument::FindFlags flags);

    // Completer
    void setCompleterList(QStringList list);
    void showCompletion();

protected:

    // Events
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void scrollContentsBy(int dx, int dy);

private:

    // Editor
    ScriptEditor *m_scriptEditor;

    // Line number area
    LineNumberArea *m_lineNumberArea;

    // Completer
    QCompleter *m_completer;
    QStringListModel *m_completerList;
    QString m_completerPrefix;
    QTimer *m_checkCompletion;

private slots:

    // Completer
    void insertCompletion(QModelIndex index);
    void insertCompletion(QString string);
    void stopCompletion();
    void checkForCompletion();

    // Line number area
    void updateLineNumberArea();
    void lineNumberAreaClicked(QPoint pos);

    // Undo/Redo
    void undoCommandAdded();

    // Match symbols
    void setMatchFormat(int pos);
    void matchSymbols();

signals:

    // Breakpoints
    void toggleBreakpoint(int line);

    // Debug
    void showDebugVariable(QString name, QPoint position);

    // Editing
    void insertPerformed();
    void undoPerformed();
    void redoPerformed();
    void lineCountChanged(int startLine, int dt);
};

class LineNumberArea : public QWidget
{
    Q_OBJECT
public:
    LineNumberArea(ScriptTextEdit *textEdit);
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    ScriptTextEdit *m_textEditor;

signals:
    void clicked(QPoint pos);
};

#include <QStyledItemDelegate>
#include <QPainter>
class CompleterDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        // Draw text
        painter->setPen(Qt::black);
        painter->setBrush(Qt::black);
        painter->drawText(option.rect, index.data().toString());

        // Draw selection
        if(option.state & QStyle::State_Selected)
        {
            // Set outline pen
            QPen pen;
            pen.setWidth(1);
            pen.setBrush(QColor(10, 80, 220, 90));
            pen.setJoinStyle(Qt::RoundJoin);

            // Create fill gradient
            QLinearGradient grad(0.0, 0.0, 0.0, 1.0);
            grad.setColorAt(0, QColor(10, 220, 220, 50));
            grad.setColorAt(1, QColor(10, 150, 220, 50));

            // Create and set brush
            QBrush brush(grad);
            painter->setPen(pen);
            painter->setBrush(brush);

            // Draw rect
            QRect drawRect(option.rect);
            drawRect.setWidth(drawRect.width()-1);
            drawRect.setHeight(drawRect.height()-1);
            painter->drawRoundedRect(drawRect, 3.0, 3.0);
        }
    }
};

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

class ScriptIntel;

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
    ScriptTextEdit *scriptTextEdit();

    // Script intel
    ScriptIntel *scriptIntel();

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
    ScriptTextEdit *m_scriptTextEdit;
    int m_changesSinceSave;

    // Script intel
    ScriptIntel *m_scriptIntel;

    // Script file
    QString m_filePath;
    QString m_defaultTitle;
    QMdiSubWindow *m_mdiWindow;
    bool m_saved;

//    QLabel *posLabel;
//    QProgressBar *inteliBar;

    // Breakpoints
    QVector<bool> m_breakpoints;

public slots:

    // Editor
    void save();
    void resetSaveState();
    void textChanged();
    void textUndo();
    void textRedo();
    void updatePositionLabel();
    void updateIntel();
    void aboutToActivate();

    // Lists
    void functionIndexChanged(QString text);
    void namedScopeIndexChanged(QString text);

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
    void toggleBreakpoint(const int line);
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
    friend class ScriptIntel;
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
