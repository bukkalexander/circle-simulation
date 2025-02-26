FROM ubuntu:20.04 AS builder

# Avoid interactive prompts during package installation.
ENV DEBIAN_FRONTEND=noninteractive

# General dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    clang-tidy \
    clang-format \
    git \
    && rm -rf /var/lib/apt/lists/*

# GLFW and GL dependencies 
RUN apt-get update && apt-get install -y \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libxcursor-dev \
    libgl1-mesa-dev \
    libglm-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

COPY . .

RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    cmake --build .

CMD [ "/bin/bash" ]


FROM ubuntu:20.04 AS release
RUN apt-get update && apt-get install -y libgl1

WORKDIR /release
COPY --from=builder /workspace/build/circle_simulation/ ./
ENTRYPOINT ["./circle_simulation"]