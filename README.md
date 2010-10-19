PSL1GHT
=======

PSL1GHT is a lightweight PlayStation 3 homebrew SDK, provided as a temporary
way to compile user apps to run from the XMB using the open-source PS3
toolchains available.


Building
--------

A GCC toolchain that supports the PowerPC 64bit architecture is required to
build PSL1GHT and its samples.
[This](http://www.bsc.es/plantillaH.php?cat_id=579) is the only toolchain
that I test with and can guarantee support for.


Status
------

At the moment, it really doesn't do that much. You can call lv2 syscalls, so
you have file access, memory management, etc. It doesn't link to PS3 dynamic
libraries yet, which is where all the exciting functionality comes in.
