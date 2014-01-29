#ifndef SCRIPTINTEL_H
#define SCRIPTINTEL_H

#include <QVector>
#include <QString>
#include <QSettings>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QMdiSubWindow>

#include <QTextEdit>
#include <QCompleter>
#include <QStringListModel>
#include <QSyntaxHighlighter>
#include <QCryptographicHash>

#include "scripteditor.h"

class ScriptIntel : public QObject
{
    Q_OBJECT
public:
    explicit ScriptIntel(QString filePath, ScriptEditor *scriptEdit);

    // Comments
    bool isCommentAt(int pos);
    AngelScriptPraser::Comment *commentAt(int pos);

private:
    QString m_filePath;
    QTextDocument *m_document;
    AngelScriptPraser *m_praser;

public:

    // Comment info
    struct Comment
    {
        int begin;
        int end;
    };

    // Script database structs
    struct Variable
    {
        QString name;
        QString type;
        QString file;
        int begin;
    };

    enum ScopeType {
        GlobalScope,
        GeneralScope,
        NamespaceScope,
        FunctionScope,
        ClassScope
    };

    struct Scope
    {
        ~Scope() {
            foreach(Scope *scope, scopes) delete scope;
            foreach(Variable *var, variables) delete var;
        }

        QString name;
        QString file;
        ScopeType type;

        QString checksum;
        int begin;
        int end;

        Scope *parent;
        QList<Scope*> scopes;
        QList<Variable*> variables;
    };

    // Database accesss
    int stackLevelAt(int idx);
    Scope* globalScope();
    Scope *scopeAt(const int pos);

private:

    // Global scope
    static Scope s_globalScope;

    // Comments
    static QVector<Comment> s_comments;

public:

    // Helper func
    static ScriptIntel::Scope *findNamedScope(ScriptIntel::Scope *currScope, QString name)
    {
        foreach(ScriptIntel::Scope *scope, currScope->scopes)
        {
            if(scope->name == name) return scope;
            ScriptIntel::Scope *findScope = findNamedScope(scope, name);
            if(findScope != 0) return findScope;
        }
        return 0;
    }

    // Static database
    static void Init();
    static void phraseFile(QString filePath);
    static void phraseFileByText(QString filePath, QString text);

private:

    // Phrasing helpers
    static QString nextWord(QTextStream *stream);
    static QString prevWord(QTextStream *stream);
    static QChar nextChar(QTextStream *stream);
    static QChar prevChar(QTextStream *stream);
    static void parentesisBegin(QTextStream *stream);
};

#endif // SCRIPTINTEL_H
