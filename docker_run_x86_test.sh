#!/usr/bin/env bash

docker container run \
--rm --name led_controller_x86_test \
-it \
led_controller_x86_test $@
