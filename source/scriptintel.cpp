#include "scriptintel.h"
#include "project.h"

//-------------------------------------------
// ScriptIntel
// The script inteligence
//-------------------------------------------

ScriptIntel::ScriptIntel(QString filePath, ScriptEditor *scriptEdit) :
    QObject(scriptEdit),
    m_filePath(filePath),
    m_document(scriptEdit->scriptTextEdit()->document())
{
    m_praser = new AngelScriptPraser(m_document);

    // Start inteli construction
    //QtConcurrent::run(constructDatabase);
}

bool ScriptIntel::isCommentAt(int pos)
{
    // Fetch block number
    QTextCursor cursor(m_document);
    cursor.setPosition(pos);
    QTextBlock block = cursor.block();

    // Get comments in block
    foreach(AngelScriptPraser::Comment comment,
            m_praser->comments.values(block.blockNumber()))
    {
        // Check for comment
        if(comment.contains(pos-block.position()))
            return true;
    }
    return false;
}

AngelScriptPraser::Comment *ScriptIntel::commentAt(int pos)
{
    // Fetch block number
    QTextCursor cursor(m_document);
    cursor.setPosition(pos);
    QTextBlock block = cursor.block();

    // Get comments in block
    foreach(AngelScriptPraser::Comment comment,
            m_praser->comments.values(block.blockNumber()))
    {
        // Check for comment
        if(comment.contains(pos-block.position()))
            return &comment;
    }
    return 0;
}

int ScriptIntel::stackLevelAt(int idx)
{
    return 0;
}

ScriptIntel::Scope *ScriptIntel::globalScope()
{
    return &s_globalScope;
}

ScriptIntel::Scope *ScriptIntel::scopeAt(const int pos)
{
    // Find scope at pos
    Scope *currScope = &s_globalScope;
    while(currScope->scopes.size() > 0)
    {
        Scope *prevScope = currScope;
        foreach(Scope *scope, currScope->scopes)
        {
            if(scope->file == m_filePath && scope->begin <= pos && scope->end >= pos)
                currScope = scope;
        }
        if(prevScope == currScope)  break;
    }
    return currScope;
}

/*void ScriptIntel::textRemoved(int idx, int size)
{
    // Make sure we have something to process
    if(size <= 0)
        return;

    // Step 1) Loop all global definitions and class definitions
    // and apply text offset
    foreach(Function *func, s_functions)
    {
        if(func->file == m_filePath)
        {
            if(func->begin >  idx) func->begin -= size;
            if(func->end > idx) func->end -= size;
            foreach(Variable var, func->variables)
            {
                if(func->variables[var.name].begin > idx) func->variables[var.name].begin -= size;
                if(func->variables[var.name].end > idx) func->variables[var.name].end -= size;
            }
        }
    }

    // Step 2) Loop all local definitions...
    foreach(Class *cls, s_classes)
    {
        if(cls->file == m_filePath)
        {
            if(cls->begin > idx) cls->begin -= size;
            if(cls->end > idx) cls->end -= size;
            foreach(Function *func, cls->methods)
            {
                if(func->begin > idx) func->begin -= size;
                if(func->end > idx) func->end -= size;
                foreach(Variable var, func->variables)
                {
                    if(func->variables[var.name].begin > idx) func->variables[var.name].begin -= size;
                    if(func->variables[var.name].end > idx) func->variables[var.name].end -= size;
                }
            }
        }
    }

    // Step 3) Update database
    // WHEN TO REMOVE A DEFINITION:
    // When the begining of the definition is in the remove range
}

void ScriptIntel::textAdded(int idx, int size)
{
    // Make sure we have something to process
    if(size <= 0)
        return;

    // Step 1) Loop all global definitions and class definitions
    // and apply text offset
    foreach(Function *func, s_functions)
    {
        if(func->file == m_filePath)
        {
            if(func->begin > idx) func->begin += size;
            if(func->end > idx) func->end += size;
            foreach(Variable var, func->variables)
            {
                if(func->variables[var.name].begin > idx) func->variables[var.name].begin += size;
                if(func->variables[var.name].end > idx) func->variables[var.name].end += size;
            }
        }
    }

    // Step 2) Loop all local definitions...
    foreach(Class *cls, s_classes)
    {
        if(cls->file == m_filePath)
        {
            if(cls->begin > idx) cls->begin += size;
            if(cls->end > idx) cls->end += size;
            foreach(Function *func, cls->methods)
            {
                if(func->begin > idx) func->begin += size;
                if(func->end > idx) func->end += size;
                foreach(Variable var, func->variables)
                {
                    if(func->variables[var.name].begin > idx) func->variables[var.name].begin += size;
                    if(func->variables[var.name].end > idx) func->variables[var.name].end += size;
                }
            }
        }
    }

    // Step 3) Update database

}*/

void ScriptIntel::Init()
{
    // Step 1) Check for exsisting database file and load it

    // Step 2) (Re)phrase main.as and its includes
    // Step 2 ALT) Generate a list of includes, then pharse them
    phraseFile(Project::getProjectDir() + "/main.as");

    // Phrase all files in /includes dir
    QDir dir(QCoreApplication::applicationDirPath() + "/includes/");
    foreach(QString enrtyPath, dir.entryList(QDir::Files))
    {
        QString filePath = QCoreApplication::applicationDirPath() + "/includes/" + enrtyPath;
        if(QFile::exists(filePath))
            phraseFile(filePath);
    }

    // Step 3) Determine which files were changed using a md5 checksum
    //QString checksum = QCryptographicHash::hash(file, QCryptographicHash::Md5);

    // Step 4) Phrase all the changed files
    //foreach(QString filePath, changedFiles)
    //    phraseFile(filePath);

    // Step 5) Connect all files to a file watcher
    // which will autmatically rephrase files if changed
}

// Database
QVector<ScriptIntel::Comment> ScriptIntel::s_comments;
ScriptIntel::Scope ScriptIntel::s_globalScope;

bool isValidName(QString str)
{
    if(str.isEmpty()) return false;
    foreach(QChar c, str)
    {
        if((c < '0' && c > '9') || (c < 'A' && c > 'Z') || (c < 'a' && c > 'z') || c == '_')
            return false;
    }
    return true;
}

// Phrase script file
void ScriptIntel::phraseFile(QString filePath)
{
    // Open file
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
        return;

    // Convert file to a text document string (needed to synchronize positions)
    QString text = QTextDocument(file.readAll()).toPlainText();

    // Phrase string
    phraseFileByText(filePath, text);
}

void ScriptIntel::phraseFileByText(QString filePath, QString text)
{
    // Find checksum
    /*QString checksum = QCryptographicHash::hash(text.toLocal8Bit(), QCryptographicHash::Md5).toHex();
    if(s_phrasedFiles.find(filePath) != s_phrasedFiles.end())
    {
        // Check if the file was changed
        if(s_phrasedFiles[filePath].checksum != checksum)
            s_phrasedFiles.erase(s_phrasedFiles.find(filePath));
        else return; // No change
    }*/

    foreach(Scope *scope, s_globalScope.scopes)
    {
        if(scope->file == filePath)
        {
            s_globalScope.scopes.removeOne(scope);
            delete scope;
        }
    }

    foreach(Variable *var, s_globalScope.variables)
    {
        if(var->file == filePath)
        {
            s_globalScope.variables.removeOne(var);
            delete var;
        }
    }

    // Create text stream
    QTextStream stream(&text);
    QChar currChar;

    // Setup comment info
    Comment comment;
    bool singleLineComment = false;
    bool multiLineComment = false;
    bool stringQuote = false;

    // Setup global scope
    ScopeType currScopeType;
    QString currScopeName;
    Scope *currScope = &s_globalScope;
    currScope->parent = 0;
    currScope->type = GlobalScope;

    // Phrase file
    while(!stream.atEnd())
    {
        // Read char and continue
        currChar = stream.read(1)[0];

        // Check for comment or string end
        if(singleLineComment)
        {
            if(currChar == '\n')
            {
                // Comment end
                singleLineComment = false;
                comment.end = stream.pos()-1;
                s_comments.push_back(comment);
                stream.seek(stream.pos()-1);
            }
            continue;
        }
        else if(multiLineComment)
        {
            if(currChar == '*')
            {
                QChar c = stream.read(1)[0];
                if(c == '/')
                {
                    // Comment end
                    multiLineComment = false;
                    comment.end = stream.pos()-1;
                    s_comments.push_back(comment);
                }
                stream.seek(stream.pos()-1);
            }
            continue;
        }
        else if(stringQuote)
        {
            if(currChar == '\"')
            {
                // Skip \" cases
                int pos = stream.pos();
                stream.seek(pos-2);
                QChar c = stream.read(1)[0];
                if(c == '\\') continue;

                // End quote
                stringQuote = false;
                stream.seek(pos);
            }
            continue;
        }

        // If current char is not a letter
        if(!currChar.isLetterOrNumber())
        {
            // Check for a comment
            if(currChar == '/')
            {
                QChar c = stream.read(1)[0];
                if(c == '/')
                {
                    // Single line comment
                    singleLineComment = true;
                    comment.begin = stream.pos()-1;
                    continue;
                }else if(c == '*'){
                    // Multi line comment
                    multiLineComment = true;
                    comment.begin = stream.pos()-1;
                    continue;
                }else{
                    if(stream.atEnd()) continue;
                    stream.seek(stream.pos()-1);
                }
            }else if(currChar == '\"')
            {
                // '"' Quotes
                stringQuote = true;
                continue;
            }

            // Check for scope definers
            if(currChar == '{')
            {
                // Create new scope
                Scope *scope = new Scope;
                scope->parent = currScope;
                scope->name = currScopeName;
                scope->type = currScopeType;
                scope->begin = stream.pos()-1;
                scope->file = filePath;
                currScope->scopes.push_back(scope);
                currScope = scope;

                // Reset scope vars
                currScopeName = "";
                currScopeType = GeneralScope;
            }
            else if(currChar == '}')
            {
                // Set curr scope to parent
                currScope->end = stream.pos()-1;
                currScope = currScope->parent;

                // To avoid serious trouble, we break if we've reached an invalid scope
                if(!currScope) break;
            }

            // Check for '#include's
            if(currChar == '#')
            {
                int pos = stream.pos();
                if(nextWord(&stream) == "include")
                {
                    // Find quotation mark
                    QChar c;
                    while((c = stream.read(1)[0]).isSpace());
                    if(c == '\"')
                    {
                        // Read file name
                        QString file;
                        while((c = stream.read(1)[0]).isLetterOrNumber())
                              file += c;

                        if(c == '\"') {
                            // Add include
                            QString dir = filePath.left(filePath.lastIndexOf('/'));
                            phraseFile(dir + "/" + file);
                            continue;
                        }
                    }
                }
                stream.seek(pos);
            }

            // Look for classes, if we're not in a class
            if(currScope->type != ClassScope)
            {
                int pos = stream.pos();
                if(nextWord(&stream) == "class")
                {
                    QString name = nextWord(&stream);
                    if(isValidName(name))
                    {
                        // Add a class scope
                        currScopeType = ClassScope;
                        currScopeName = name;
                        continue;
                    }
                }
                stream.seek(pos);
            }

            // Look for functions
            if(currChar == '(')
            {
                // Find function name
                int pos = stream.pos();
                stream.seek(pos-1);
                QString name = prevWord(&stream);
                if(prevChar(&stream) != '@') stream.seek(stream.pos()+1); // Handle var
                QString ret = prevWord(&stream);
                stream.seek(pos);

                // Check for constructors and destructors
                if(currScope->type == ClassScope)
                {
                    if(name == currScope->name) ret = currScope->name /*+ "@"*/;
                    else if(name == "~" + currScope->name) ret = "void";
                }

                // Check for valid names
                if(!isValidName(name) || !isValidName(ret))
                    continue;

                // Phrase arguments
                QString args; QChar c;
                while(!stream.atEnd() && (c = stream.read(1)[0]) != ')')
                      args += c;

                // Make sure it is is a function def
                if(nextChar(&stream) != '{')
                {
                    stream.seek(pos);
                    continue;
                }

                // Add a function scope
                currScopeType = FunctionScope;
                currScopeName = name;
                stream.seek(stream.pos()-1);
                continue;
            }

            // Look for variable declarations
            if(currChar == ';')
            {
                // There are many ways variables are declared, here we try to hande all of them
                QStringList nameList;
                QString type;
                int currPos = stream.pos();
                int defPos = 0;

                while(true)
                {
                    QChar c;

                    // Add all var defs
                    int pos = stream.pos()-1;
                    stream.seek(pos);
                    c = prevChar(&stream);
                    stream.seek(pos);

                    if(c == ')')
                    {
                        // Convert these cases:
                        // Class c(5, 3);
                        // Class c = Class(1, 1);
                        // Class c1 = Class(1, 1), c2 = Class(2, 2);
                        // Class @c = @Class(1, 1);

                        // Skip arguments
                        parentesisBegin(&stream);
                    }

                    // Cases:
                    // Class c;
                    // Class c = Class;
                    // Class c1, c2;
                    // Class c1 = Class, Class c2 = Class;
                    // Class @c;
                    // Class @c = @Class;

                    // Get var name
                    QString name = prevWord(&stream);

                    // Get prev char
                    c = prevChar(&stream);
                    if(c == '@') c = prevChar(&stream); // Handle var
                    if(c == '=')
                    {
                        // Get object name
                        stream.seek(stream.pos()+1);
                        name = prevWord(&stream);
                        c = prevChar(&stream);
                        if(c == '@') c = prevChar(&stream); // Handle var
                        if(c == ',')
                        {
                            // Store name
                            nameList << name;
                            continue; // Next object in the list
                        }else{
                            // Read object type
                            stream.seek(stream.pos()+1);
                            type = prevWord(&stream);
                            nameList << name;
                            defPos = stream.pos();
                            break; // There "should" be no more objects
                        }
                    }
                    else if(c == ',') // Case 3
                    {
                        // Add object to list
                        nameList << name;
                        continue; // Next object in the list
                    }
                    else // Case 1
                    {
                        // Read object type
                        stream.seek(stream.pos()+1);
                        type = prevWord(&stream);
                        nameList << name;
                        defPos = stream.pos();
                        break; // There "should" be no more objects
                    }
                }

                // Add variable(s) if valid
                if(/*c != '.' && */type != "return" && type != "else" && isValidName(type))
                {
                    foreach(QString name, nameList)
                    {
                        if(isValidName(name))
                        {
                            Variable *variable = new Variable;
                            variable->name = name;
                            variable->type = type;
                            variable->file = filePath;
                            variable->begin = defPos;
                            currScope->variables.push_back(variable);
                        }
                    }
                }

                stream.seek(currPos);
            }
        }
    }

    // Add files to phrased files list
    //s_phrasedFiles[filePath].checksum = checksum;
}

bool isValidChar(QChar c)
{
    if((c == '\0' || c == ' ' || c == '\n' || c == '\t' || c == '\r') || // NULL SPC NL
            (c >= '0' && c <= '9') || // 0-9
            (c >= 'A' && c <= 'Z') || // A-Z
            (c >= 'a' && c <= 'z'))   // a-z
        return true;
    return false;
}

QString ScriptIntel::nextWord(QTextStream *stream)
{
    // Find next char
    QChar c;
    while(!(c = stream->read(1)[0]).isLetterOrNumber())
    {
        if(!isValidChar(c) || stream->atEnd())
            return "";
    }
    stream->seek(stream->pos()-1);

    // Read word
    QString word;
    while((c = stream->read(1)[0]).isLetterOrNumber())
        word += c;
    stream->seek(stream->pos()-1);

    // Return word
    return word;
}

QString ScriptIntel::prevWord(QTextStream *stream)
{
    // Find prev char
    QChar c;
    stream->seek(stream->pos()-1);
    while(!(c = stream->read(1)[0]).isLetterOrNumber()) {
        if(!isValidChar(c) || stream->pos() < 2) return "";
        stream->seek(stream->pos()-2);
    }

    // Read word
    QString word;
    stream->seek(stream->pos()-1);
    while(((c = stream->read(1)[0]).isLetterOrNumber() || c == '.') && stream->pos() >= 1) {
        word.push_front(c);
        stream->seek(stream->pos()-2);
    }

    // Return word
    return word;
}

QChar ScriptIntel::nextChar(QTextStream *stream)
{
    QChar c;
    while((c = stream->read(1)[0]).isSpace())
    {
        // Make sure not eof
        if(stream->atEnd())
            return '\0';
    }
    return c;
}

QChar ScriptIntel::prevChar(QTextStream *stream)
{
    // Find prev char
    stream->seek(stream->pos()-1);
    QChar c;
    while((c = stream->read(1)[0]).isSpace())
        stream->seek(stream->pos()-2);
    stream->seek(stream->pos()-1);
    return c;
}

void ScriptIntel::parentesisBegin(QTextStream *stream)
{
    int parentesisCount = 0;
    stream->seek(stream->pos()-1);
    do{
        QChar c = stream->read(1)[0];
        if(c == ')')
            parentesisCount++;
        else if(c == '(')
            parentesisCount--;
        stream->seek(stream->pos()-2);
    }while(stream->pos() > 0 && parentesisCount > 0);
    stream->seek(stream->pos()+1);
}
