# LED Controller
Welcome! This is a simple LED controller.
The goal of this project is to take a very simple concept (blink an LED) and focus on the design, implementation, and evolution of a product.


## Details
Rather than speculate, let's actively explore and quantify the differences between design decisions.
This project implements several different end-user products using three different techniques:

    * AVR libraries
        - Directly reference AVR-specific tools, functions, and registers
    * Hardware abstraction library
        - Wrap the direct AVR references in a library, libhw_attiny861
    * Software abstraction library
        - Create software structures that model specific end-user behavior

Unsurprisingly, with each abstraction layer the size of the executable increases and the amount of interaction with chip-specific hardware decreases.


## Structure
Here is a high-level view of the project:
```
led_controller
├── analysis            # Various dumps of image sizes and assembly code
├── doc                 # Notes on individual moving parts - soon to be real documentation
├── include             # For software abstraction layer
├── lib                 # Hardware abstraction library
├── products            # Products written with software abstraction layer
├── products_avr        # Products written with AVR libraries directly
├── products_libhw      # Products written with hardware abstraction library
├── src                 # For software abstraction layer
└── tests               # For software abstraction layer
```


## Unit tests
All modules are unit tested using [CppUTest](http://cpputest.github.io/) with the exception of the high-level executables (I don't yet know how to do this).
For instructions on how to build and run these tests, see the [unit test README](README_unit_tests.md).


## Requirements

    * Local compilation
        - gcc
        - CMake
        - CppUTest
    * Cross compilation
        - AVR gcc
        - CMake
        - AVRDUDE


## Local compilation
This project can be compiled and tested on a PC.
For specific build instructions, see the [build README](README_build.md).


## Cross compilation
Products are designed to run on AVR hardware.
For specific build instructions, see the [build README](README_build.md).
