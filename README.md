PSL1GHT
=======

PSL1GHT is a lightweight PlayStation 3 homebrew SDK, provided as a temporary
way to compile user apps to run from the XMB using the open-source PS3
toolchains available.

**PSL1GHT has moved to [HACKERCHANNEL](http://github.com/HACKERCHANNEL/PSL1GHT).
This fork may or may not serve as my development branch, and may or may not
be updated at all anymore. So go there instead for "official" releases.**


Environment
-----------

A GCC toolchain that supports the PowerPC 64bit architecture is required to
build PSL1GHT and its samples. It also requires the toolchain to provide
a full newlib environment; at the moment only two toolchains do so:

* [ps3chain](http://github.com/HACKERCHANNEL/ps3chain)
* [ps3toolchain](http://github.com/ooPo/ps3toolchain)

The SDK also includes a few standalone tools to help compilation. A host gcc
is required to build raw2h, and Python 2.x is required to run make_fself.py

Building
--------

Run make install in the psl1ght directory to build it all, and make sure to
set the environment variable $PSL1GHT to the folder where you wish to
install it to, for example...

    cd /path/to/psl1ght.git
    export PSL1GHT=/path/to/psl1ght.git/build
    make
    make install

... for a local build of it. Ensure that $PSL1GHT is set when you are
building any of the examples or other apps that use PSL1GHT.


Status
------

At the moment, PSL1GHT has basic libc support, with stdout debugging, file
access, etc. It doesn't have any way to access the screen/graphics. You can
call lv2 syscalls and do some fun stuff with that, but it doesn't link to
PS3 dynamic libraries yet which is where all the exciting functionality
comes in.
