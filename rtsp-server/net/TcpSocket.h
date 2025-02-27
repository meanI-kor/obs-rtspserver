// PHZ
// 2018-5-15
// Scott Xu
// 2020-12-2 Add IPv6 Support. 

#ifndef XOP_TCP_SOCKET_H
#define XOP_TCP_SOCKET_H

#include <cstdint>
#include <string>
#include "Socket.h"

namespace xop
{
    
class TcpSocket
{
public:
	TcpSocket(SOCKET sockfd = -1, bool ipv6 = false);
	virtual ~TcpSocket();

	SOCKET Create(bool ipv6 = false);
	bool Bind(std::string ip, uint16_t port);
	bool Listen(int backlog);
	SOCKET Accept();
	bool Connect(std::string ip, uint16_t port, int timeout = 0);
	void Close();
	void ShutdownWrite();

	SOCKET GetSocket() const { return sockfd_; }
	bool IsIpv6Socket() const { return ipv6_; }
    
private:
	SOCKET sockfd_ = 0;
	bool ipv6_;
};

}

#endif



