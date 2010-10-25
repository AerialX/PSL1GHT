#include <psl1ght/lv2.h>

LV2_SYSCALL lv2TimerUSleep(u64 time) { return Lv2Syscall1(141, time); }
LV2_SYSCALL lv2TimerSleep(u64 time) { return Lv2Syscall1(142, time); }
