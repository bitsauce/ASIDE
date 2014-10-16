#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <QObject>
#include <QTabWidget>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QTextDocument>
#include <QTextDocumentFragment>
#include <QFile>
#include <QFileInfo>
#include <QLocalSocket>
#include <QTableWidget>
#include <QHeaderView>
#include <QProcess>

class ProfilerWidget;
class OutputWidget;
class ErrorWidget;
enum XPacketType;

//-----------------------------------------------------
// Debugger
//-----------------------------------------------------
class Debugger : public QObject
{
    Q_OBJECT
public:
    Debugger(QTabWidget *infoWidget, QWidget *parent = 0);

    // Connect to host (game)
    void connectToHost();
    void reset();

    // Running?
    bool isRunning() { return m_debugging; }

    // Breakpoints
    void addBreakpoint(const QString &filePath, const int line);
    void removeBreakpoint(const QString &filePath, const int line);
    void currentBreakLocation(QString &filePath, int &line);

public slots:

    // Manual break
    void interrupt();
    void resume();
    void stop();

    void stepOver();
    void stepInto();
    void stepOut();

    void startProfiler();
    void stopProfiler();

private slots:
    void cellDoubleClicked(int row, int col);
    void processPacket();
    void gameEnded(int ret, QProcess::ExitStatus status);
    void sendAllBreakpoints();

signals:
    void execInitialized();
    void execInterrupted(QString filePath, int line);
    void execResumed();
    void execEnded();

private:
    // Socket
    QLocalSocket *m_socket;

    // Output widget
    OutputWidget *m_outputWidget;

    // Error list widget
    QTableWidget *m_errorWidget;

    // Profiler
    ProfilerWidget *m_profiler;

    // Packet
    QByteArray m_packet;

    // Running?
    bool m_debugging;

    // Breakpoints
    struct Breakpoint
    {
        QString filePath;
        int line;

        bool operator==(const Breakpoint &other) {
            return filePath == other.filePath && line == other.line;
        }
    };
    QList<Breakpoint> m_breakpoints;
    QString m_breakFilePath;
    int m_breakLine;
};

extern Debugger *debugger();

//-----------------------------------------------------
// Output widget
//-----------------------------------------------------
class OutputWidget : public QTextEdit
{
    Q_OBJECT
public:
    OutputWidget(QWidget *parent = 0) :
        QTextEdit(parent)
    {
        // Read only
        setReadOnly(true);

        // Setup a monospace font
        QFont monoFont("Courier New", 8, QFont::Normal);
        monoFont.setStyleHint(QFont::Monospace);
        setFont(monoFont);
    }

    void mouseDoubleClickEvent(QMouseEvent *e);
    void contextMenuEvent(QContextMenuEvent *e)
    {
        QMenu *menu = createStandardContextMenu();
        QAction *clearAll = menu->addAction("Clear All");
        connect(clearAll, SIGNAL(triggered()), this, SLOT(clear()));
        menu->exec(e->globalPos());
        delete menu;
    }
};

//---------------------------------------------------------------
// Error widget: Shows errors and warnings in an organized
// manner.
//--------------------------------------------------------------
/*class ErrorWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit ErrorWidget(QWidget *parent = 0);


};*/

#endif // DEBUGGER_H
