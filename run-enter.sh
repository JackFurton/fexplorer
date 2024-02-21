#!/usr/bin/env bash
#
#
docker build -t valgrind .

docker run -it -v prg:/root/prg valgrind
