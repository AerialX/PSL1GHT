#include <psl1ght/lv2.h>

int main()
{
	// This example calls the TTY_WRITE syscall. You can view this
	// message by using a payload that hooks TTY_WRITE and displays
	// it somewhere (perhaps using PL3's self_elf network code?)
	Lv2Syscall(403, 1, (u64)"ohai\n", 5, NULL, 0, 0, 0, 0);

	// Until exit() is implemented (liblv2's sys_process_exit),
	// this actually returns to crt0 and causes an instruction exception.
	// Conveniently, the exception throws us back to XMB :)
	return 0;
}
