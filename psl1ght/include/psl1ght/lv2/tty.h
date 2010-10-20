#pragma once

#include <psl1ght/lv2.h>

LV2_SYSCALL lv2TtyWrite(int channel, const void* buffer, u32 size, u32* written) { return Lv2Syscall4(403, channel, (u64)buffer, size, (u64)written); }

LV2_SYSCALL lv2TtyRead(int channel, void* buffer, u32 size, u32* read) { return Lv2Syscall4(402, channel, (u64)buffer, size, (u64)read); }
