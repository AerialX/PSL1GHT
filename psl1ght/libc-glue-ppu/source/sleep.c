#include <unistd.h>
#include <psl1ght/lv2/timer.h>
#include <psl1ght/lv2/errno.h>

int usleep(useconds_t usec)
{
	return lv2Errno(lv2TimerUSleep(usec));
}

unsigned int sleep(unsigned int seconds)
{
	s32 ret = lv2TimerSleep(seconds);
	if (ret)
		return seconds; // TODO: Check what lv2TimerSleep returns
	return 0;
}

