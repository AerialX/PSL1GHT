#!/usr/bin/env python
from __future__ import with_statement
from Struct import Struct
import struct

"""
	This is a quick and dirty implementation of make_fself based on the
	documentation collected here:
		http://ps3wiki.lan.st/index.php/Self_file_format
	It's not ment to look pretty, or be well documented but just provide
	an alternative to using the illegal Sony SDK until a better solution
	is released. (Such as a propper ELF loader built into lv2)
					-- phiren
"""

class SelfHeader(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.magic	= Struct.uint32
		self.headerVer  = Struct.uint32
		self.flags	= Struct.uint16
		self.type	= Struct.uint16
		self.meta	= Struct.uint32
		self.headerSize = Struct.uint64
		self.encryptedSize = Struct.uint64
		self.unknown	= Struct.uint64
		self.AppInfo	= Struct.uint64
		self.elf	= Struct.uint64
		self.phdr	= Struct.uint64
		self.shdr	= Struct.uint64
		self.phdrOffsets = Struct.uint64
		self.sceversion = Struct.uint64
		self.digest	= Struct.uint64
		self.digestSize = Struct.uint64
		self.padding    = Struct.uint64

class AppInfo(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.authid	= Struct.uint64
		self.unknown	= Struct.uint32
		self.appType	= Struct.uint32
		self.appVersion = Struct.uint64
		self.padding    = Struct.uint64

class phdrOffset(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.offset	= Struct.uint64
		self.size	= Struct.uint64
		self.unk1	= Struct.uint32
		self.unk2	= Struct.uint32
		self.unk3	= Struct.uint32
		self.unk4	= Struct.uint32

class Digest(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.type1		= Struct.uint32
		self.size1		= Struct.uint32
		self.continue1		= Struct.uint64
		self.magicBits		= Struct.uint8[0x14]
		self.digest		= Struct.uint8[0x14]
		self.padding		= Struct.uint8[0x08]
		self.type2		= Struct.uint32
		self.size2		= Struct.uint32
		self.continue2		= Struct.uint64
		self.magic 		= Struct.uint32
		self.unk1 		= Struct.uint32
		self.drmType 		= Struct.uint32
		self.unk2		= Struct.uint32
		self.contentID 		= Struct.uint8[0x30]
		self.fileSHA1 		= Struct.uint8[0x10]
		self.notSHA1 		= Struct.uint8[0x10]
		self.notXORKLSHA1 	= Struct.uint8[0x10]
		self.nulls 		= Struct.uint8[0x10]

class Elf64_ehdr(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.ident 		= Struct.uint8[16]
		self.type		= Struct.uint16
		self.machine		= Struct.uint16
		self.version		= Struct.uint32
		self.entry		= Struct.uint64
		self.phoff		= Struct.uint64
		self.shoff		= Struct.uint64
		self.flags		= Struct.uint32
		self.ehsize		= Struct.uint16
		self.phentsize		= Struct.uint16
		self.phnum		= Struct.uint16
		self.shentsize		= Struct.uint16
		self.shnum		= Struct.uint16
		self.shstrndx		= Struct.uint16

class Elf64_phdr(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.type	= Struct.uint32
		self.flags	= Struct.uint32
		self.offset	= Struct.uint64
		self.vaddr	= Struct.uint64
		self.paddr	= Struct.uint64
		self.filesz	= Struct.uint64
		self.memsz	= Struct.uint64
		self.align	= Struct.uint64

class sceVersion(Struct):
	__endian__ = Struct.BE
	def __format__(self):
		self.unk1	= Struct.uint32
		self.unk2	= Struct.uint32
		self.unk3	= Struct.uint32
		self.unk4	= Struct.uint32
		self.unk5	= Struct.uint16
		self.unk6	= Struct.uint16
		self.unk7	= Struct.uint32
		self.unk8	= Struct.uint32
		self.unk9	= Struct.uint32
		self.offset	= Struct.uint64
		self.size	= Struct.uint64

def readElf(filename):
	with open(filename, 'rb') as fp:
		data = fp.read()
		ehdr = Elf64_ehdr()
		ehdr.unpack(data[0:len(ehdr)])
		phdrs = []
		offset = ehdr.phoff
		for i in range(ehdr.phnum):
			phdr = Elf64_phdr()
			phdr.unpack(data[offset:offset+len(phdr)])
			offset += len(phdr)
			phdrs.append(phdr)
		
		return data, ehdr, phdrs

def createFself(filename, outfile="EBOOT.BIN"):
	elf, ehdr, phdrs = readElf(filename)
	
	header = SelfHeader()
	appinfo = AppInfo()
	digest = Digest()

	headerSize = len(header) + len(appinfo) + len(digest) + len(ehdr)
	headerSize+= len(phdrs) * (0x38 + 0x20)

	padding = 0x80 - (headerSize % 0x80)
	headerSize += padding

	header.magic = 0x53434500
	header.headerVer = 2
	header.flags = 0x8000
	header.type = 1
	header.meta = headerSize - 0x20 - padding
	header.headerSize = headerSize
	header.encryptedSize = len(elf)
	header.unknown = 3
	header.AppInfo = len(header)
	header.elf = len(header) + len(appinfo)
	header.phdr = header.elf + len(ehdr)
	header.shdr = headerSize + ehdr.shoff
	header.phdrOffsets = header.phdr + len(phdrs) * 0x38
	header.sceVersion = 0
	header.digest = headerSize - len(digest) - padding
	header.digestSize = len(digest)

	appinfo.authid = 0x1010000001000003
	appinfo.unknown = 0x1000002
	appinfo.appType = 0x4
	appinfo.appVersion = 0x0001000000000000

	digest.type0 = 1
	digest.size0 = 0x30
	digest.continue0 = 1
	digest.type1 = 2
	digest.size1 = 0x40
	digest.continue1 = 1
	digest.magicBits = (0x62, 0x7c, 0xb1, 0x80, 0x8a, 0xb9, 0x38, 0xe3, 0x2c, 0x8c, 0x09, 0x17, 0x08, 0x72, 0x6a, 0x57, 0x9e, 0x25, 0x86, 0xe4)
	digest.type2 = 3
	digest.size2 = 0x90
	digest.continue2 = 0
	digest.magic = 0x4e504400
	digest.unk1 = 1
	digest.drmType = 2
	digest.unk2 = 1
	digest.contentID = [0x30] * 0x2f + [0]
	digest.fileSHA1 = (0x42, 0x69, 0x74, 0x65, 0x20, 0x4d, 0x65, 0x2c, 0x20, 0x53, 0x6f, 0x6e, 0x79, 0x00, 0xde, 0x07)
	digest.notSHA1 = [0xaa] * 0x10
	digest.notXORKLSHA1 = [0x00] * 0x0f + [0x01]

	offsets = []
	for phdr in phdrs:
		offset = phdrOffset()
		offset.offset = phdr.offset + headerSize
		offset.size = phdr.filesz
		offset.unk1 = 1
		offset.unk2 = 0
		offset.unk3 = 0
		if phdr.type == 1:
			offset.unk4 = 2
		else:
			offset.unk4 = 0
		offsets.append(offset)

	out = open(outfile, 'wb')
	out.write(header.pack())
	out.write(appinfo.pack())
	out.write(ehdr.pack())
	for phdr in phdrs:
		out.write(phdr.pack())
	for offset in offsets:
		out.write(offset.pack())
	out.write(digest.pack())
	out.write("\0" * padding)
	out.write(elf)

import sys

if len(sys.argv) == 2:
	createFself(sys.argv[1])
elif len(sys.argv) == 3:
	createFself(sys.argv[1], sys.argv[2])
else:
	print "make_fself.py usage:\n  make_self.py input.elf [output]\n  If output file is not specified, make_fself.py will default to EBOOT.BIN"

