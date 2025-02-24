FROM ubuntu:20.04

# Avoid interactive prompts during package installation.
ENV DEBIAN_FRONTEND=noninteractive


RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    clang-tidy \
    clang-format \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD [ "bash" ]
