FROM ubuntu:20.04

# So programs like tzdata don't stop the image build process
ARG DEBIAN_FRONTEND=noninteractive

# Install our base dependencies
RUN apt-get update &&\
    apt-get install -y \
        apt-utils \
        wget nano jq \
        build-essential gdb \
        git \
        cmake \
        python3-dev python3-pip

# Install ctypesgen and jq bindings for ctypes generation
RUN pip3 install ctypesgen jq