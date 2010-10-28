#pragma once

#include <psl1ght/lv2.h>

#include <sys/socket.h>

typedef u32 lv2_socklen_t;

struct lv2_iovec
{
	u32			padding1;
	lv2_void	iov_base;
	u32			padding2;
	lv2_size_t	iov_len;
};

struct lv2_msghdr
{
	u32				padding1;
	lv2_void		msg_name;
	lv2_socklen_t	msg_namelen;
	u32				padding2;
	u32				padding3;
	lv2_void		msg_iov;
	s32				msg_iovlen;
	u32				padding4;
	u32				padding5;
	lv2_void		msg_control;
	lv2_socklen_t	msg_controllen;
	s32				msg_flags;
};

LV2_SYSCALL lv2NetConnect(int socket, const struct sockaddr* address, lv2_socklen_t address_len) { return Lv2Syscall3(702, socket, (u64)address, address_len); }
LV2_SYSCALL lv2NetSendto(int socket, const void* message, size_t length, int flags, const struct sockaddr* dest_addr, socklen_t dest_len) { return Lv2Syscall6(710, socket, (u64)message, length, flags, (u64)dest_addr, dest_len); }
LV2_SYSCALL lv2NetShutdown(int socket, int how) { return Lv2Syscall2(712, socket, how); }
LV2_SYSCALL lv2NetSocket(int domain, int type, int protocol) { return Lv2Syscall3(713, domain, type, protocol); }
LV2_SYSCALL lv2NetClose(int socket) { return Lv2Syscall1(714, socket); }
