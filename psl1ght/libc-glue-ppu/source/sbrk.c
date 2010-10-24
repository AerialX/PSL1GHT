#include <psl1ght/lv2.h>

#include <stddef.h>
#include <errno.h>

// 64kb page allocations
#define PAGE_SIZE		0x10000
#define PAGE_SIZE_FLAG	0x200

#define ROUND_UP(p, round) \
	((p + round - 1) & ~(round - 1))

// Here's a very lazy and lossy sbrk. It's made of fail, but I'm lazy.
char* memend = 0;
void* sbrk(long increment)
{
	if (increment == 0)
		return memend;
	if (increment < 0)
		return memend;
	size_t allocsize = ROUND_UP(increment, PAGE_SIZE);
	int addr;
	if (Lv2Syscall3(348, allocsize, PAGE_SIZE_FLAG, (u64)&addr)) {
		errno = ENOMEM;
		return (void*)-1;
	}
	memend = (char*)(u64)addr;
	memend += increment;
	return (void*)(u64)addr;
}
