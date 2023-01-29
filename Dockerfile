FROM ubuntu:22.04

ENV DEBIAN_FRONTEND noninteractive
ENV IDF_GITHUB_ASSETS dl.espressif.com/github_assets
ENV IDF_TOOLS_PATH /espressif
ENV ESP_IDF_VERSION v5.0
ENV LC_ALL C

WORKDIR /

RUN apt update \
    && apt install -y git curl wget minicom flex bison gperf python3 python3-venv locales \
        cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0 clang-tidy \
    && dpkg-reconfigure locales \
    && apt -y clean \
    && apt -y autoremove \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir espressif \
    && git clone --recursive --branch ${ESP_IDF_VERSION} https://github.com/espressif/esp-idf.git \
    && /esp-idf/install.sh all \
    && sh -c "echo 'source /esp-idf/export.sh' >> /etc/bash.bashrc"

