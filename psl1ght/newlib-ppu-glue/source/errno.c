#include <errno.h>

int* __errno_location()
{
	return __errno();
}
