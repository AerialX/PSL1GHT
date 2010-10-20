.global ._start
._start:
	mflr	%r0
	stdu	%r1, -0x80(%r1)
	std		%r0, 0x70(%r1)
	li		%r2, 0
	std		%r2, 0x00(%r1)
	lis		%r2, _start@h
	ori		%r2, %r2, _start@l
	ld		%r2, 0x08(%r2)
	bl		._initialize
	ld		%r0, 0x70(%r1)
	addi	%r1, %r1, 0x80
	mtlr	%r0
	blr
	

.section ".opd","aw"
.global _start
_start:
	.quad ._start
	.quad .TOC.@tocbase
	.quad 0

