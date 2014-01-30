#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <winsock2.h>
#include <windows.h>
#include <windowsx.h>
#include <string>
#include <vector>
#include <list>
#include <assert.h>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

class Debugger
{
public:
	Debugger() :
		m_connected(false),
		m_command(NoCommand),
		m_prevStackSize(0),
		m_timeoutValue(5000),
		m_server(INVALID_SOCKET),
		m_client(INVALID_SOCKET)
	{
	}

	// Packet types
	enum PacketType {
		NullPacket = 0x00,
		ConnectedPacket,
		InitializedPacket,
		MessagePacket,
		CompilePacket,
		BreakpointPacket,
		TextVariablePacket,
		ImageVariablePacket,
	};

	enum MessageType {
		PrintMsg,
		WarningMsg,
		SuccessMsg,
		ErrorMsg
	};
	
	bool init();
	void setTimeoutValue(const unsigned int ms);
	bool listen(const unsigned short port);
	bool accept();
	void disconnect();
	bool send(const char *data);
	bool recv(char **data);
	int  bytesReady();
	
	/*********************************************************************
	**	Implemented part												**
	**********************************************************************/
	bool connect();
	void sendPacket(PacketType type, const char *data = 0);
	void sendMessage(const string &data, const MessageType type);
	void recvPacket(char **data);

	void lineCallback(void *ctx);
	bool isBreakpoint(void *ctx);
	void takeCommands(void *ctx);

private:
	enum Command
	{
		NoCommand = 0x00,
		Continue,
		Interupt,
		StepOver,
		StepInto,
		StepOut,
		AddBreakpoint,
		RemoveBreakpoint
	};
	Command m_command;

	struct Breakpoint
	{
		string file;
		int line;
        bool operator==(const Breakpoint &other) {
            return file == other.file && line == other.line;
        }
	};
	list<Breakpoint> m_breakpoints;

	bool m_connected;
	int m_prevStackSize;
	unsigned int m_timeoutValue;

	// Sockets
	SOCKET m_server;
	SOCKET m_client;
};

#endif // DEBUGGER_H