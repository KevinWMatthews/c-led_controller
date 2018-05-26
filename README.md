# ATtiny861 Hardware Abstraction Library
Hardware abstraction library for the ATtiny861 processor.


## Table of Contents

  * [Quick Start](#quick-start)
  * [Background](#background)
    - [Design](#design)
    - [Organization](#organization)
  * [Build](#build)
    - [Docker Compilation](#docker-compilation)
    - [Local Compilation](#local-compilation)
    - [Cross Compilation](#cross-compilation)
    - [Unit Tests](#unit-tests)


## Quick Start
To see an example of compiling and testing the library, execute the scripts to build and run a Docker container:
```bash
$ ./docker_build_x86_test.sh
$ ./docker_run_x86_test.sh
```
This, of course, requries Docker to be installed on your system.


## Background
Starting from a simple concept (blink an LED), design, implement, test, and evolve a hardware abstraction library and a series of examples. Rather than speculate, actively explore and quantify the differences between design decisions.


### Design
This project illustrates three different design:

    * AVR library
        - Directly reference AVR-specific tools, functions, and registers
    * Hardware abstraction library
        - Wrap the direct AVR references in a library, libATtiny861
    * Software abstraction library
        - Wrap the hardware abstraction library in a software abstraction layer
        - Model real-world objects

Unsurprisingly, with each abstraction layer the size of the executable increases and the amount of interaction with chip-specific hardware decreases.


### Organization
Here is a high-level view of the project:
```bash
.
├── doc
├── Dockerfiles
├── examples
│   ├── avr             # AVR library
│   ├── libATtiny861    # Hardware abstraction library 
│   └── sw_abstraction  # Software abstraction library
├── include
├── mocks
├── src
└── tests
```


## Requirements

  * Docker compilation
    - Docker
  * Local compilation
    - gcc
    - CMake
    - CppUTest (for unit tests only)
  * Cross compilation
    - AVR gcc
    - CMake
    - AVRDUDE


## Build


### Docker Compilation
Some parts of the project can be compiled and run using Docker (more are coming).
For specific build instructions, see the [Dockerfiles README](Dockerfiles/README.md).


### Local Compilation
This project can be compiled and tested on a PC.
For specific build instructions, see the [build README](doc/README_build.md).


### Cross Compilation
Examples are designed to run on AVR ATtiny861 hardware.
For specific build instructions, see the [build README](doc/README_build.md).


### Unit Tests
All modules are unit tested using [CppUTest](http://cpputest.github.io/) with the exception of the high-level executables.
For instructions on how to build and run these tests, see the [unit test README](tests/README.md) or the [Dockerfiles README](Dockerfiles/README.md).
