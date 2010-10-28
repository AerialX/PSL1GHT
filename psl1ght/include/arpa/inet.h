#pragma once

#include <netinet/in.h>
#include <stdint.h>

#define htonl(hostlong)		(hostlong)
#define htons(hostshort)	(hostshort)
#define ntohl(netlong)		(netlong)
#define ntohs(netshort)		(netshort)

in_addr_t inet_addr(const char* cp);
in_addr_t inet_lnaof(struct in_addr in);
struct in_addr inet_makeaddr(in_addr_t net, in_addr_t lna);
in_addr_t inet_netof(struct in_addr in);
in_addr_t inet_network(const char* cp);
char* inet_ntoa(struct in_addr in);
int inet_aton(const char* cp, struct in_addr* inp);
const char* inet_ntop(int af, const void* src, char* dst, socklen_t size);
int inet_pton(int af, const char* src, void* dst);
