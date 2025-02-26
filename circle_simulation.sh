#!/bin/bash
set -e

IMAGE_NAME=circle_simulation_release

docker build --quiet -t ${IMAGE_NAME} .>/dev/null

# For nvidia gpu, add --gpus all instead of --device /dev/dri (not tested)
docker run --rm -it \
    --device /dev/dri \
    -e DISPLAY=$DISPLAY \
    -e XAUTHORITY=/root/.Xauthority \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v $XAUTHORITY:/root/.Xauthority \
    ${IMAGE_NAME} "$@"
