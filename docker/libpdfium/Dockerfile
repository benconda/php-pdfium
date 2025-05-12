FROM ubuntu:24.04

ENV OS=linux
ENV CPU=arm64

RUN apt-get update && apt-get install -y \
    git \
    sudo \
    curl \
    python3 \
    file \
    lsb-base \
    lsb-release

RUN git clone https://github.com/bblanchon/pdfium-binaries.git /home/ubuntu/pdfium-binaries

WORKDIR /home/ubuntu/pdfium-binaries

CMD ./build.sh ${OS} ${CPU}