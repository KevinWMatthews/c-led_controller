# Mock AVR Register

This directory contains mocks/simulations for ATtiny hardware, in particular ```<avr/*.h>``` header files and the memory registers found therein.
It contains copies of AVR special register macros (PORT, PIN, etc) and local variables that are referenced by these macros.

Defining variables to act as registers enables a standard gcc compiler to build source and test files that have a direct hardware dependency.
It also enables tests to inspect the contents of the chip's simulated memory registers.

The original AVR header files are located in ```avr/include/``` in your AVR toolchain directory.
