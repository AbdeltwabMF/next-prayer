#!/bin/bash
#
# Continuous Integration and Delevary script

# Build
make clean install
# Verify
next-prayer --version
# Test
docker container run -e RUN_LOCAL=true -v "$(PWD)":/tmp/lint github/super-linter
# Create docker image
docker build -t next-prayer .
docker tag next-prayer abdeltwabmf/next-prayer:2.0.0
docker tag next-prayer abdeltwabmf/next-prayer:latest
# Push to docker hub
docker push abdeltwabmf/next-prayer:2.0.0
docker push abdeltwabmf/next-prayer:latest
