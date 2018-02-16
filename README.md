# LED Controller
Welcome! This is a simple LED controller.
It is intended to be an example of unit tested design patterns as a simple project grows to be complex.

## Structure
A variety of different products are provided. These typically are implemented using three different techniques:

    * AVR libraries
        - Directly reference AVR-specific tools, functions, and registers
    * Hardware abstraction library
        - Wrap the direct AVR references in a library, libhw_attiny861
    * Software abstraction layer
        - Create software structures that model specific end-user behavior

Unsurprisingly, with each abstraction layer the size of the executable increases and the amount of interaction with chip-specific hardware (hopefully) decreases.

## Unit tests
All modules should be fully unit tested during their creation, with the exception of the high-level executable (I don't know how to test this).
Unit tests are built within the [CppUTest](http://cpputest.github.io/) framework.
For instructions on how to build and run these tests, see the unit test README. 

## Requirements

    * Cross compilation
        - AVR gcc
        - CMake
    * Local compilation
        - gcc
        - CMake
        - CppUTest

## Build Setup
This project was designed to be built with CMake.
This is primarily so that it is compatible with CLion and secondarily because I'm sick of using autotools.
For specific build instructions, see the build README.
