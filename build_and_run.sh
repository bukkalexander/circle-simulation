#!/bin/bash
set -e


IMAGE_NAME=circle_simulation

echo "Building Docker image..."
docker build -t ${IMAGE_NAME} .

echo "Building the project inside Docker..."
docker run --rm -v "$(pwd)":/workspace -w /workspace ${IMAGE_NAME} bash -c "\
    mkdir -p build && cd build && cmake .. && cmake --build ."

echo "Running the executable inside Docker..."
docker run --rm -v "$(pwd)":/workspace -w /workspace ${IMAGE_NAME} ./build/circle_simulation
