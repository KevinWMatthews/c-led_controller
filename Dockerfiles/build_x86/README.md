# Dockerfile for Local Build

This Dockerfile is designed for compiling and running unit tests on a PC.
The project source code is cloned into the image and the build setup
(out-of-tree build, CMake configuration) has been run.
This provides a consistent starting point for compilation and testing.

This image is not designed for development!
Build results exist only within the container and do not persist on the host machine.

It does not allow cross-compilation - there is a separate Docker image for this.


## Pull Image from DockerHub

TODO I will push an image to DockerHub.


## Build Image Locally

```
$ cd c-led_controller
$ docker build -t led_controller_build_x86 Dockerfiles/led_controller/build_x86/
```


## Run Container

Start a bash prompt in the container using:

```
$ docker container run --rm docker build -it led_controller_x86 bash
```

Within the container there is a source directory and an out-of-tree build:
```
.
|-- c-led_controller
`-- c-led_controller_build
```

### Unit Tests

To run unit tests,
```
$ cd ~/c-led_controller_build
$ make
$ make test
```

Test groups can be run individually:
```
$ ./bin/Test_ATtiny861 -c
$ ./bin/Test_LedController -c
```

### Inspect Source

To inspect the source code,
```
cd ~/c-led_controller
```
