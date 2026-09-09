FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    wget \
    xz-utils \
    python3 \
    cmake \
    make \
    git \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# ARM GCC toolchain — identical version to ofp, same controlled compiler
WORKDIR /opt
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz && \
    tar -xf gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz && \
    rm gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz

ENV PATH="/opt/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf/bin:${PATH}"

WORKDIR /fcs_model

# Verify installations
RUN aarch64-none-elf-gcc --version && \
    gcc --version && \
    cmake --version && \
    python3 --version && \
    git --version

CMD ["/bin/bash"]