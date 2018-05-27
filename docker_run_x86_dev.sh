#!/usr/bin/env bash

user=$(id --user)
group=$(id --group)

#TODO add bash argument parsing

HOST_SOURCECODE_PATH=${SOURCECODE_PATH?'Must set environment variable SOURCECODE_PATH'}
HOST_BUILDDIR_PATH=${BUILDDIR_PATH?'Must set environment variable BUILDDIR_PATH'}
TARGET_SOURCECODE_PATH=$HOME/$(basename $HOST_SOURCECODE_PATH)
TARGET_BUILDDIR_PATH=$HOME/$(basename $HOST_BUILDDIR_PATH)

docker run \
    --rm --name libATtiny861_x86_dev \
    --user $user:$group \
    --mount type=bind,src=$HOST_SOURCECODE_PATH,dst=$TARGET_SOURCECODE_PATH \
    --mount type=bind,src=$HOST_BUILDDIR_PATH,dst=$TARGET_BUILDDIR_PATH \
    -w $TARGET_BUILDDIR_PATH \
    -it \
    libattiny861_x86_dev $@
