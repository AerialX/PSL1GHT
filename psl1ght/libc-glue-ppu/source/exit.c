#include <unistd.h>

void _fini();

void _exit(int status)
{
	_fini();
	// liblv2's sys_process_exit, or even at least sys_ppu_thread_exit
}
