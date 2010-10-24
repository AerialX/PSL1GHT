#include <stdlib.h>

int main(int argc, const char* argv[], const char* envp[]);

void _init();

static const char* envp[] = { 0 };
const char** environ = envp;

int _initialize(int argc, const char* argv[])
{
	_init();
	int ret = main(argc, argv, envp);
	exit(ret);
	return ret;
}
