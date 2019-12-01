#!/usr/bin/env bash

dir=$(pwd)
server=/usr/src/cppweb/hello_world/build/hello_world
#docker run -v "$dir"/cppweb:/usr/src/cppweb -p 8888:8888 -e PORT=8888 hello_world:latest "$server"
docker run -p 8888:8888 -e PORT=8888 hello_static:latest "$server"
