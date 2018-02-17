# LED Controller
Welcome! This is a simple LED controller.
It is intended to be an example of unit tested design patterns as a simple project grows to be complex.


## Structure
A variety of different products are implemented. As an exercise, the majority of these are duplicated using three different techniques:

    * AVR
        - Directly reference AVR-specific tools, functions, and registers
    * Hardware abstraction
        - Wrap the direct AVR references in a library, libhw_attiny861
    * Software abstraction
        - Create software structures that model specific end-user behavior

Unsurprisingly, with each abstraction layer the size of the executable increases and the amount of interaction with chip-specific hardware (hopefully) decreases.


## Unit tests
All modules were unit tested during their creation, with the exception of the high-level executables (I don't know how to test this).
Unit tests leverage the [CppUTest](http://cpputest.github.io/) framework.
For instructions on how to build and run these tests, see the [unit test README](README_unit_tests).


## Requirements

    * Cross compilation
        - AVR gcc
        - CMake
        - AVRDUDE
    * Local compilation
        - gcc
        - CMake
        - CppUTest


## Local compilation
This project can be compiled and tested on a PC without the need for target hardware emulation.
For specific build instructions, see the [build README](README_build.md).


## Cross compilation
This project can be compiled and run on AVR hardware.
For specific build instructions, see the [build README](README_build.md).
