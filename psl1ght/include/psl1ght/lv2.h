#pragma once

#include <psl1ght/types.h>

// lv2 retail 3.41
#define LV2_SYSCALL_TABLE	0x80000000002EB128ULL

#define LV2_INLINE static inline __attribute__((unused))
#define LV2_SYSCALL LV2_INLINE s32

#define __lv2syscallarg0 
#define __lv2syscallarg1 __lv2syscallarg0, u64 a1
#define __lv2syscallarg2 __lv2syscallarg1, u64 a2
#define __lv2syscallarg3 __lv2syscallarg2, u64 a3
#define __lv2syscallarg4 __lv2syscallarg3, u64 a4
#define __lv2syscallarg5 __lv2syscallarg4, u64 a5
#define __lv2syscallarg6 __lv2syscallarg5, u64 a6
#define __lv2syscallarg7 __lv2syscallarg6, u64 a7
#define __lv2syscallarg8 __lv2syscallarg7, u64 a8
#define __lv2syscallargt0 
#define __lv2syscallargt1 u64
#define __lv2syscallargt2 __lv2syscallargt1, u64
#define __lv2syscallargt3 __lv2syscallargt2, u64
#define __lv2syscallargt4 __lv2syscallargt3, u64
#define __lv2syscallargt5 __lv2syscallargt4, u64
#define __lv2syscallargt6 __lv2syscallargt5, u64
#define __lv2syscallargt7 __lv2syscallargt6, u64
#define __lv2syscallargt8 __lv2syscallargt7, u64
#define __lv2syscall0 
#define __lv2syscall1 a1
#define __lv2syscall2 __lv2syscall1, a2
#define __lv2syscall3 __lv2syscall2, a3
#define __lv2syscall4 __lv2syscall3, a4
#define __lv2syscall5 __lv2syscall4, a5
#define __lv2syscall6 __lv2syscall5, a6
#define __lv2syscall7 __lv2syscall6, a7
#define __lv2syscall8 __lv2syscall7, a8

#ifdef LV2
#define __lv2syscall(num) \
	LV2_INLINE u64 Lv2Syscall##num(u64 syscall __lv2syscallarg##num) \
	{ \
		u64 (*syscallopd)(__lv2syscallargt##num) = (u64 (*)(__lv2syscallargt##num))*(u64*)(LV2_SYSCALL_TABLE + syscall * 8); \
		return syscallopd(__lv2syscall##num); \
	}

__lv2syscall(0);
__lv2syscall(1);
__lv2syscall(2);
__lv2syscall(3);
__lv2syscall(4);
__lv2syscall(5);
__lv2syscall(6);
__lv2syscall(7);
__lv2syscall(8);
#else
#define __lv2syscallclobber8 "r0", "r2", "r12", "lr", \
	"ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", \
	"memory"
#define __lv2syscallclobber7 __lv2syscallclobber8, "r10"
#define __lv2syscallclobber6 __lv2syscallclobber7, "r9"
#define __lv2syscallclobber5 __lv2syscallclobber6, "r8"
#define __lv2syscallclobber4 __lv2syscallclobber5, "r7"
#define __lv2syscallclobber3 __lv2syscallclobber4, "r6"
#define __lv2syscallclobber2 __lv2syscallclobber3, "r5"
#define __lv2syscallclobber1 __lv2syscallclobber2, "r4"
#define __lv2syscallclobber0 __lv2syscallclobber1, "r3"
#define __lv2syscallreg(num, reg) \
	register u64 p##num asm(reg) = a##num
#define __lv2syscallregs \
	register u64 s asm("11") = syscall
#define __lv2syscallparam1(reg) reg(p1), reg(s)
#define __lv2syscallparam2(reg) reg(p1), reg(p2), reg(s)
#define __lv2syscallparam3(reg) reg(p1), reg(p2), reg(p3), reg(s)
#define __lv2syscallparam4(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(s)
#define __lv2syscallparam5(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(s)
#define __lv2syscallparam6(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(s)
#define __lv2syscallparam7(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(p7), reg(s)
#define __lv2syscallparam8(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(p7), reg(p8), reg(s)
LV2_INLINE u64 Lv2Syscall0(u64 syscall __lv2syscallarg0) {
	__lv2syscallregs;
	register u64 p1 asm("3") = 0;
	asm volatile("sc"
			: __lv2syscallparam1("=r")
			: __lv2syscallparam1("r")
			: __lv2syscallclobber1);
	return p1;
}
LV2_INLINE u64 Lv2Syscall1(u64 syscall __lv2syscallarg1) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	asm volatile("sc"
			: __lv2syscallparam1("=r")
			: __lv2syscallparam1("r")
			: __lv2syscallclobber1);
	return p1;
}
LV2_INLINE u64 Lv2Syscall2(u64 syscall __lv2syscallarg2) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	asm volatile("sc"
			: __lv2syscallparam2("=r")
			: __lv2syscallparam2("r")
			: __lv2syscallclobber2);
	return p1;
}
LV2_INLINE u64 Lv2Syscall3(u64 syscall __lv2syscallarg3) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	asm volatile("sc"
			: __lv2syscallparam3("=r")
			: __lv2syscallparam3("r")
			: __lv2syscallclobber3);
	return p1;
}
LV2_INLINE u64 Lv2Syscall4(u64 syscall __lv2syscallarg4) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	asm volatile("sc"
			: __lv2syscallparam4("=r")
			: __lv2syscallparam4("r")
			: __lv2syscallclobber4);
	return p1;
}
LV2_INLINE u64 Lv2Syscall5(u64 syscall __lv2syscallarg5) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	asm volatile("sc"
			: __lv2syscallparam5("=r")
			: __lv2syscallparam5("r")
			: __lv2syscallclobber5);
	return p1;
}
LV2_INLINE u64 Lv2Syscall6(u64 syscall __lv2syscallarg6) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	asm volatile("sc"
			: __lv2syscallparam6("=r")
			: __lv2syscallparam6("r")
			: __lv2syscallclobber6);
	return p1;
}
LV2_INLINE u64 Lv2Syscall7(u64 syscall __lv2syscallarg7) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	__lv2syscallreg(7, "9");
	asm volatile("sc"
			: __lv2syscallparam7("=r")
			: __lv2syscallparam7("r")
			: __lv2syscallclobber7);
	return p1;
}
LV2_INLINE u64 Lv2Syscall8(u64 syscall __lv2syscallarg8) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	__lv2syscallreg(7, "9");
	__lv2syscallreg(8, "10");
	asm volatile("sc"
			: __lv2syscallparam8("=r")
			: __lv2syscallparam8("r")
			: __lv2syscallclobber8);
	return p1;
}
#endif

#ifdef __cplusplus
#define __lv2syscallcomma0
#define __lv2syscallcomma1 ,
#define __lv2syscallcomma2 ,
#define __lv2syscallcomma3 ,
#define __lv2syscallcomma4 ,
#define __lv2syscallcomma5 ,
#define __lv2syscallcomma6 ,
#define __lv2syscallcomma7 ,
#define __lv2syscallcomma8 ,
#define __lv2syscallcpp(num) \
	LV2_INLINE u64 Lv2Syscall(u64 syscall __lv2syscallarg##num) \
	{ \
		return Lv2Syscall##num(syscall __lv2syscallcomma##num __lv2syscall##num); \
	}
__lv2syscallcpp(0);
__lv2syscallcpp(1);
__lv2syscallcpp(2);
__lv2syscallcpp(3);
__lv2syscallcpp(4);
__lv2syscallcpp(5);
__lv2syscallcpp(6);
__lv2syscallcpp(7);
__lv2syscallcpp(8);
#endif
