#!/usr/bin/env bash

NEWLIB_VERSION=1.18.0

if [ -z $PSL1GHT ]; then
	echo "You must set \$PSL1GHT in your environment."
	exit 1
fi

if [ -d newlib-$NEWLIB_VERSION ]; then
	exit 0
fi

wget -c ftp://sources.redhat.com/pub/newlib/newlib-$NEWLIB_VERSION.tar.gz
tar xvf newlib-$NEWLIB_VERSION.tar.gz
cat newlib.patch | patch -p0

export CC_FOR_TARGET=ppu-gcc
export GCC_FOR_TARGET=ppu-gcc
export CXX_FOR_TARGET=ppu-g++
export LD_FOR_TARGET=ppu-ld
export AS_FOR_TARGET=ppu-as
export AR_FOR_TARGET=ppu-ar
export RANLIB_FOR_TARGET=ppu-ranlib
export NM_FOR_TARGET=ppu-nm
export STRIP_FOR_TARGET=ppu-strip
export OBJDUMP_FOR_TARGET=ppu-objdump
export OBJCOPY_FOR_TARGET=ppu-objcopy

mkdir -p newlib-ppu
pushd newlib-ppu
../newlib-$NEWLIB_VERSION/configure --target=ppc64 --prefix=$PSL1GHT/newlib
popd

export CC_FOR_TARGET=spu-gcc
export GCC_FOR_TARGET=spu-gcc
export CXX_FOR_TARGET=spu-g++
export LD_FOR_TARGET=spu-ld
export AS_FOR_TARGET=spu-as
export AR_FOR_TARGET=spu-ar
export RANLIB_FOR_TARGET=spu-ranlib
export NM_FOR_TARGET=spu-nm
export STRIP_FOR_TARGET=spu-strip
export OBJDUMP_FOR_TARGET=spu-objdump
export OBJCOPY_FOR_TARGET=spu-objcopy

mkdir -p newlib-spu
pushd newlib-spu
../newlib-$NEWLIB_VERSION/configure --target=spu --prefix=$PSL1GHT/newlib
popd
