#pragma once

#include <psl1ght/lv2.h>

LV2_INLINE lv2TtyWrite(int channel, const void* buffer, u32 size, u32* written) { return Lv2Syscall(403, channel, (u64)buffer, size, (u64)written, 0, 0, 0, 0); }

LV2_INLINE lv2TtyRead(int channel, void* buffer, u32 size, u32* read) { return Lv2Syscall(402, channel, (u64)buffer, size, (u64)read, 0, 0, 0, 0); }
