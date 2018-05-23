# Dockerfile for Local Build

This Dockerfile is designed for compiling and running unit tests on a PC.
The project source code is cloned into the image and a CMake out-of-tree build is set up.
This provides a consistent starting point for compiling and running all tests.

This image is not designed for development!
Build results exist only within the container and do not persist on the host machine.

This image is designed for local compilation only.


## Pull Image from DockerHub

TODO I will push an image to DockerHub.


## Build Image Locally

To build the Docker image for running unit tests on x86, use the provided shell script:
```
$ cd c-led_controller
$ ./docker_build_x86_test.sh
```

Or build the image manually:
```
$ cd c-led_controller
$ docker build -t led_controller_x86_test Dockerfiles/x86_test/
```


## Run Container

Build and run tests in the Docker container using
```
$ cd c-led_controller
$ ./docker_run_x86_test.sh
```


### Enter Container

The bash script will pass any arguments to the container that it starts. For example, use
```
$ ./docker_run_x86_test.sh bash
```
to launch a shell in the container.

Within the container there is a source directory and an out-of-tree build directory:
```
.
|-- c-led_controller
`-- c-led_controller_build
```


### Unit Tests

Unit tests are run automatically when the container is launched.

To manually run unit tests within the container, first shell into the container. Then run
```
# From within ~/c-led_controller_build
$ make
$ make test
```

Test groups can be run individually:
```
# From within ~/c-led_controller_build
$ ./bin/Test_ATtiny861 -c
$ ./bin/Test_LedController -c
```

### Inspect Source

To inspect the source code,
```
cd ~/c-led_controller
```
