#pragma once

#include <psl1ght/types.h>

#include <sys/socket.h>

typedef u16 in_port_t;
typedef u32 in_addr_t;

struct in_addr
{
	in_addr_t s_addr;
};

struct sockaddr_in
{
	u8				sin_len;
	sa_family_t		sin_family;
	in_port_t		sin_port;
	struct in_addr	sin_addr;
	unsigned char	sin_zero[0x08];
};

#define IPPROTO_IP		0x00
#define IPPROTO_ICMP	0x01
#define IPPROTO_TCP		0x06
#define IPPROTO_UDP		0x11
#define IPPROTO_ICMPV6	0x3A

#define INADDR_ANY			0x00000000
#define INADDR_LOOPBACK		0x7F000001
#define INADDR_BROADCAST	0xFFFFFFFF
#define INADDR_NONE			0xFFFFFFFF

#include <arpa/inet.h>
