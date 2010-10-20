PSL1GHT
=======

PSL1GHT is a lightweight PlayStation 3 homebrew SDK, provided as a temporary
way to compile user apps to run from the XMB using the open-source PS3
toolchains available.


Environment
-----------

A GCC toolchain that supports the PowerPC 64bit architecture is required to
build PSL1GHT and its samples.
[This](http://www.bsc.es/plantillaH.php?cat_id=579) is the only toolchain
that I test with and can guarantee support for.
[PS3Chain](http://github.com/HACKERCHANNEL/ps3chain) probably works just as
well, as should marcan's [AsbestOS](http://git.marcansoft.com/?p=asbestos.git)
toolchain. Some toolchains will probably already use newlib, and will make
the included newlib unnecessary.


Building
--------

Run make in the psl1ght directory to build it all. Then set the environment
variable $PSL1GHT to the folder where you wish to install it to, for example

  export PSL1GHT=/path/to/psl1ght/build

... for a local build of it somewhere. Make sure this is set when you are
building any of the examples.


Status
------

At the moment, PSL1GHT has basic libc support, with stdout debugging, file
access, etc. You can call lv2 syscalls and do some fun stuff with that, but
it doesn't link to PS3 dynamic libraries yet which is where all the
exciting functionality comes in. Also, a make_fself equivalent is still
missing.
