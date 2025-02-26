#!/bin/bash
set -e

IMAGE_NAME=circle_simulation_release

echo "Building Docker image..."
docker build -t ${IMAGE_NAME} .

echo "Creating release folder..."
rm -rf release
mkdir release

echo "Extracting executable from Docker image..."
CONTAINER_ID=$(docker create ${IMAGE_NAME})
docker cp ${CONTAINER_ID}:/release/circle_simulation release/circle_simulation
docker rm ${CONTAINER_ID}

echo "Copying release notes..."
cp release_template.md release/README.md

echo "Appending recent git log as release notes..."
echo -e "\n## Release Notes\n" >> release/README.md
git log --pretty=format:"* %h - %s (%ci)" >> release/README.md

RELEASE_ID=$(git describe --tags --exact-match 2>/dev/null || git rev-parse --short HEAD)
ZIPNAME="circle_simulation_release_${RELEASE_ID}.zip"

echo "Zipping release folder into ${ZIPNAME}..."
rm -f ${ZIPNAME}
zip -r ${ZIPNAME} release

echo "Release created: ${ZIPNAME}"
