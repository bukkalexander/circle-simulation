#!/bin/bash
set -e


IMAGE_NAME=circle_simulation

echo "Building Docker image..."
docker build -t ${IMAGE_NAME} .

echo "Building the project inside Docker..."
docker run --rm -v "$(pwd)":/workspace -w /workspace ${IMAGE_NAME} bash -c "\
    mkdir -p build && cd build && cmake .. && cmake --build ."

echo "Running the executable inside Docker..."
# For nvidia gpu, add --gpus all instead of --device /dev/dri (not tested)
docker run --rm \
    --device /dev/dri \
    -e DISPLAY=$DISPLAY \
    -e XAUTHORITY=/root/.Xauthority \
    -v "$(pwd)":/workspace \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v $XAUTHORITY:/root/.Xauthority \
    -w /workspace \
    ${IMAGE_NAME} /bin/bash -c " ./build/circle_simulation"
