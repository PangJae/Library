#include "stdafx.h"
#include "Socket.h"
using namespace std;



Adress::Adress()
{
	ZeroMemory(&m_addr, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
}
Adress::Adress(const char* address, int port)
{
	ZeroMemory(&m_addr, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	inet_pton(AF_INET, address, &m_addr.sin_addr);
	m_addr.sin_port = htons((uint16_t)port);
}
Adress::~Adress()
{
}


SocketInit g_socketInit;
SocketInit::SocketInit()
{
	WSADATA w;
	WSAStartup(MAKEWORD(2, 2), &w);
}

Socket::Socket()
{
	return;
}
Socket::Socket(SOCKET fd, const SOCKADDR_IN& addr)
{
	m_fd = fd;
	m_addr = addr;
}
Socket::~Socket()
{

}


string GetLastErrorAsString()
{
	int error = WSAGetLastError();
	char errorMsg[100];
	sprintf(errorMsg, "\nerror [%d]\n", error);
}