//     _    ____ ___ ____  _____
//    / \  / ___|_ _|  _ \| ____|
//   / _ \ \___ \| || | | |  _|
//  / ___ \ ___) | || |_| | |___
// /_/   \_\____/___|____/|_____|
// Originally written by Marcus Loo Vergara (aka. Bitsauce)
// 2011-2014 (C)

#include "debugger.h"
#include "scripteditor.h"
#include "workspace.h"
#include "project.h"
#include "profiler.h"

#include <x2d/x2d.h>

// Global debugger

Debugger *g_debugger = 0;
Debugger *debugger()
{
    return g_debugger;
}

Debugger::Debugger(QTabWidget *infoWidget, QWidget *parent) :
    QObject(parent),
    m_debugging(false),
    m_breakFilePath(""),
    m_breakLine(0)
{
    // Global debugger
    Q_ASSERT(!g_debugger);
    g_debugger = this;

    // Create socket object
    m_socket = new QLocalSocket(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(processPacket()));
    //connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));

    // Create output widget tab
    m_outputWidget = new OutputWidget(infoWidget);
    infoWidget->addTab(m_outputWidget, "Output");

    // Create error list widget tab
    {
        m_errorWidget = new QTableWidget(infoWidget);
        m_errorWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        connect(m_errorWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(cellDoubleClicked(int,int)));

        QHeaderView *header = m_errorWidget->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::ResizeToContents);

        m_errorWidget->setColumnCount(4);
        m_errorWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Type"));
        m_errorWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Message"));
        m_errorWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("File"));
        m_errorWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Line"));

        infoWidget->addTab(m_errorWidget, "Error List");
    }

    // Create profiler
    {
        m_profiler = new ProfilerWidget(infoWidget);
        infoWidget->addTab(m_profiler, "Profiler");
        connect(m_profiler, SIGNAL(start()), this, SLOT(startProfiler()));
        connect(m_profiler, SIGNAL(stop()), this, SLOT(stopProfiler()));
    }

    // Create variable
    infoWidget->addTab(0, "Variable List");
}

void Debugger::connectToHost()
{
    // Connect to host
    while(m_socket->state() != QLocalSocket::ConnectedState)
        m_socket->connectToServer("\\\\.\\pipe\\x2d_debug_pipe");
    m_debugging = true;
}

void Debugger::processPacket()
{
    // Read byte data
    QByteArray arrayData = m_socket->readAll();
    const char *data = arrayData.data();

    // Extract packet type
    XPacketType packetType = XPacketType(data[0]);
    QString packet = (data + 1);
    switch(packetType)
    {
    case XD_MESSAGE_PACKET:
        if(packet[0] == '#' && packet.size() > 7)
        {
            // Apply text color
            QColor textColor(packet.mid(0, 7));
            if(textColor.isValid())
                packet.remove(0, 7);
            else
                textColor = Qt::black;
            m_outputWidget->setTextColor(textColor);
        }else{
            m_outputWidget->setTextColor(Qt::black);
        }

        // Append to log
        m_outputWidget->append(packet);
    break;

    case XD_COMPILE_ERROR_PACKET:
    {
        // Get compile data
        QStringList callbackData = packet.split(" : ");
        if(callbackData.size() == 3)
        {
            // Create compilation list item
            int row = m_errorWidget->rowCount();
            QString loc = callbackData[0];
            QString type = callbackData[1];
            m_errorWidget->setRowCount(row+1);
            QTableWidgetItem *item;

            // Type
            item = new QTableWidgetItem(type);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            m_errorWidget->setItem(row, 0, item);

            // Message
            item = new QTableWidgetItem(callbackData[2]);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            m_errorWidget->setItem(row, 1, item);

            // File
            item = new QTableWidgetItem(loc.left(loc.indexOf('(')-1));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            m_errorWidget->setItem(row, 2, item);

            // Line
            item = new QTableWidgetItem(loc.mid(loc.indexOf('(')+1, loc.indexOf(',')-loc.indexOf('(')-1));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            m_errorWidget->setItem(row, 3, item);
        }
    }
    break;

    case XD_BREAK_PACKET:
    {
        QStringList split = packet.split(";");
        m_breakFilePath = split[0];
        m_breakLine = split[1].toInt();
        ScriptEditor *edit = (ScriptEditor*)workspace()->openFile(m_breakFilePath);
        edit->gotoLine(m_breakLine);
        emit execInterrupted(m_breakFilePath, m_breakLine);
    }
    break;

    case XD_PUSH_NODE_PACKET:
        m_profiler->push(packet.split(";"));
    break;

    case XD_POP_NODE_PACKET:
        m_profiler->pop();
    break;

    case XD_STEP_DONE_PACKET:
        m_profiler->update();
    break;

    default:
        qDebug() << "Unknown packet type '" << packetType << "'!";
    break;
    }

    // Send packet
    m_packet.prepend(XD_ACK_PACKET);
    char *ackPacket = new char[m_packet.size() + 1];
    memcpy(ackPacket, m_packet.constData(), m_packet.size());
    ackPacket[m_packet.size()] = '\0';
    m_socket->write((const char*)ackPacket);

    // Setup next packet
    m_packet.clear();
}

void Debugger::gameEnded(int ret, QProcess::ExitStatus status)
{
    if(status == QProcess::CrashExit)
    {
        m_outputWidget->setTextColor(QColor("#de0000"));
        m_outputWidget->append("Game crashed...");
    }

    if(ret < 0)
    {
        m_outputWidget->setTextColor(QColor("#de0000"));
        m_outputWidget->append(QString("Exit unsuccessful with error code '%1'").arg(ret));
    }
    else
    {
        m_outputWidget->setTextColor(QColor("#00adeb"));
        m_outputWidget->append("Exit successful");
    }

    m_profiler->applicationEnd();
    m_outputWidget->append("");
    m_debugging = false;
}

void Debugger::sendAllBreakpoints()
{

}

void Debugger::reset()
{
    m_profiler->applicationStart();
    m_errorWidget->setRowCount(0);
    m_outputWidget->clear();
}

void Debugger::addBreakpoint(const QString &filePath, const int line)
{
    Breakpoint bp = { filePath, line };
    m_breakpoints.push_back(bp);
    if(m_debugging)
    {
        QByteArray packet = QString(" %2;%3").arg(filePath).arg(line).toLatin1();
        packet[0] = 0x6;
        packet.resize(512);
        m_socket->write(packet);
    }
}

void Debugger::removeBreakpoint(const QString &filePath, const int line)
{
    Breakpoint bp = { filePath, line };
    m_breakpoints.removeOne(bp);
    if(m_debugging)
    {
        QByteArray packet = QString(" %2;%3").arg(filePath).arg(line).toLatin1();
        packet[0] = 0x7;
        packet.resize(512);
        m_socket->write(packet);
    }
}

void Debugger::currentBreakLocation(QString &filePath, int &line)
{
    filePath = m_breakFilePath;
    line = m_breakLine;
}

void Debugger::interrupt()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x8;
    m_socket->write(packet);
}

void Debugger::resume()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x9;
    m_socket->write(packet);
}

void Debugger::stop()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x10;
    m_socket->write(packet);
}

void Debugger::stepOver()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x11;
    m_socket->write(packet);
}

void Debugger::stepInto()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x12;
    m_socket->write(packet);
}

void Debugger::stepOut()
{
    QByteArray packet(512, '\0');
    packet[0] = 0x13;
    m_socket->write(packet);
}

void Debugger::startProfiler()
{
    m_packet.append(XD_START_PROFILER);
}

void Debugger::stopProfiler()
{
    m_packet.append(XD_STOP_PROFILER);
}

void Debugger::cellDoubleClicked(int row, int)
{
    QString filePath = m_errorWidget->item(row, 2)->text();
    int line = m_errorWidget->item(row, 3)->text().toInt();

    ScriptEditor *editor = (ScriptEditor*)workspace()->openFile(Project::getDirectory() + filePath);
    if(editor) editor->scrollToLine(line-1);
}

void OutputWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    // Process mouse double click
    QTextEdit::mouseDoubleClickEvent(e);

    // Get block under cursor
    QTextCursor cursor = cursorForPosition(e->pos());
    int colNum = cursor.columnNumber();
    cursor.select(QTextCursor::BlockUnderCursor);
    QString block = cursor.selection().toPlainText();
    block.remove('\n');

    // Check for file link
    int parentesisBegin = block.indexOf('(');
    if(parentesisBegin < 0) return;
    int parentesisEnd = block.indexOf(')', parentesisBegin);
    if(parentesisEnd < colNum) return;

    // Get file path
    QString file = block.left(parentesisBegin-1);
    if(QFile::exists(file))
    {
        // Get line and col
        QStringList param = block.mid(parentesisBegin+1, parentesisEnd-parentesisBegin-1).split(',');
        int line = param[0].toInt();
        int col = param[1].toInt();

        // Open file
        ScriptEditor *editor = (ScriptEditor*)workspace()->openFile(file);
        if(!editor)
            return; // Not a valid file

        // Scroll to and select line
        editor->scrollToLine(line);

//        QTextCursor scriptCursor = editor->scriptTextEdit()->textCursor();
//        scriptCursor.setPosition(0);
//        scriptCursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line-1);
//        scriptCursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, col-1);
//        editor->scriptTextEdit()->setTextCursor(scriptCursor);

//        // Update text cursor
//        cursor.setPosition(cursor.block().position());
//        cursor.setPosition(cursor.block().position()+parentesisEnd+1, QTextCursor::KeepAnchor);
//        setTextCursor(cursor);
    }
}


/*ErrorWidget::ErrorWidget(QWidget *parent) :
    QTableView(parent)
{
}
*/
