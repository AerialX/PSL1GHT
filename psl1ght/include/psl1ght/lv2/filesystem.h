#pragma once

#include <psl1ght/lv2.h>

#include <time.h>
#include <unistd.h>

typedef s32 Lv2FsMode;
typedef s32 Lv2FsFile;
//typedef s64 time_t;

// Open Flags
/*#define O_RDONLY	000000
#define O_WRONLY	000001
#define O_RDWR		000002
#define O_ACCMODE	000003
#define O_CREAT		000100
#define O_EXCL		000200
#define O_TRUNC		001000
#define O_APPEND	002000*/

// Seek Types
/*#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2*/

// Dir Modes
/*#define	S_IFDIR		0040000
#define	S_IFREG		0100000
#define	S_IFLNK		0120000*/

typedef struct {	
	Lv2FsMode st_mode;
	s32 st_uid;
	s32 st_gid;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	u64 st_size;
	u64 st_blksize;
} Lv2FsStat;

typedef struct {
	u8 d_type;
	u8 d_namlen;
	char d_name[MAXPATHLEN + 1];
} Lv2FsDirent;

typedef struct {
	time_t actime;
	time_t modtime;
} Lv2FsUtime;

LV2_INLINE lv2FsOpen(const char* path, s32 oflags, Lv2FsFile* fd, u64 unk, const void* arg, u64 argsize) { return Lv2Syscall(801, (u64)path, oflags, (u64)fd, unk, (u64)arg, argsize, 0, 0); }
LV2_INLINE lv2FsRead(Lv2FsFile fd, void* buf, u64 size, u64* read) { return Lv2Syscall(802, fd, (u64)buf, size, (u64)read, 0, 0, 0, 0); }
LV2_INLINE lv2FsWrite(Lv2FsFile fd, const void* buf, u64 size, u64* written) { return Lv2Syscall(803, fd, (u64)buf, size, (u64)written, 0, 0, 0, 0); }
LV2_INLINE lv2FsClose(Lv2FsFile fd) { return Lv2Syscall(804, fd, 0, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsOpenDir(const char* path, Lv2FsFile* fd) { return Lv2Syscall(805, (u64)path, (u64)fd, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsReadDir(Lv2FsFile fd, Lv2FsDirent* entry, u64* read) { return Lv2Syscall(806, fd, (u64)entry, (u64)read, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsCloseDir(Lv2FsFile fd) { return Lv2Syscall(807, fd, 0, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsStat(const char* path, Lv2FsStat* buf) { return Lv2Syscall(808, (u64)path, (u64)buf, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsFstat(Lv2FsFile fd, Lv2FsStat* buf) { return Lv2Syscall(809, fd, (u64)buf, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsMkdir(const char* path, Lv2FsMode mode) { return Lv2Syscall(811, (u64)path, mode, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsRename(const char* path, const char* newpath) { return Lv2Syscall(812, (u64)path, (u64)newpath, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsRmdir(const char* path) { return Lv2Syscall(813, (u64)path, 0, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsUnlink(const char* path) { return Lv2Syscall(814, (u64)path, 0, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsLSeek64(Lv2FsFile fd, s64 offset, s32 whence, u64* position) { return Lv2Syscall(818, fd, offset, whence, (u64)position, 0, 0, 0, 0); }
LV2_INLINE lv2FsFsync(Lv2FsFile fd) { return Lv2Syscall(820, fd, 0, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsTruncate(const char* path, u64 size) { return Lv2Syscall(831, (u64)path, size, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsFtruncate(Lv2FsFile fd, u64 size) { return Lv2Syscall(832, fd, size, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsUtime(const char* path, const Lv2FsUtime* times) { return Lv2Syscall(815, (u64)path, (u64)times, 0, 0, 0, 0, 0, 0); }
LV2_INLINE lv2FsChmod(const char* path, Lv2FsMode mode) { return Lv2Syscall(834, (u64)path, mode, 0, 0, 0, 0, 0, 0); }
