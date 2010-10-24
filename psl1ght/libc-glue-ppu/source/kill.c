#include <signal.h>

#include <errno.h>

int kill(pid_t pid, int signal)
{
	errno = ENOSYS;
	return -1;
}
