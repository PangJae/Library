#pragma once
#include <winsock2.h>
#include <Windows.h>
#include <MSWSock.h>
#include <string>

class Adress
{
public:
	Adress();
	Adress(const char* address, int port);
	~Adress();
private:
	sockaddr_in m_addr;

};
class SocketInit
{
public:

	SocketInit();
};
extern SocketInit g_socketInit;


class Socket
{
public:
	static const int MaxRecvLength = 8192;


	SOCKET m_fd;
	SOCKADDR_IN m_addr;

	// AcceptEx 함수 포인터
	LPFN_ACCEPTEX AcceptEx = NULL;

	Socket();
	Socket(SOCKET fd, const SOCKADDR_IN& addr);
	~Socket();

	void Bind(const SOCKADDR_IN& addr);
	void Connect(const SOCKADDR_IN& addr);
	void Listen();
	void SetNonblocking();

	int Accept(Socket& acceptedSocket, std::string& errorText);

	int UpdateAcceptContext(Socket& listenSocket);

	int Send(const char* data, int length);
	int Receive();

	void Close();

	SOCKADDR GetAddress();

};

std::string GetLastErrorAsString();

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "mswsock.lib");
