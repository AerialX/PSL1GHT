#include <psl1ght/lv2.h>
#include <psl1ght/lv2/errno.h>

#include <errno.h>

s32 lv2Errno(s32 error)
{
	if (!error)
		return 0;

	errno = EINVAL; // TODO: Actually convert the error codes
	return -1;
}
