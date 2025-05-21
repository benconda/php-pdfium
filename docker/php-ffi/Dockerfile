FROM php:8.2-cli-bookworm AS base
ARG TARGETPLATFORM

ADD https://github.com/mlocati/docker-php-extension-installer/releases/latest/download/install-php-extensions /usr/local/bin/

RUN chmod +x /usr/local/bin/install-php-extensions && \
    install-php-extensions ffi

RUN apt-get update && apt-get install -y --no-install-recommends libvips42 && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/lib-pdfium

ENV VIPSHOME=/usr/local

WORKDIR /usr/php-pdfium

FROM base AS precompiled
ARG TARGETPLATFORM

# Translate TARGETPLATFORM to architecture format
RUN ARCH=$(echo ${TARGETPLATFORM} | cut -d'/' -f2 | sed 's/amd/x/') && \
    mkdir -p /usr/lib-pdfium && cd /usr/lib-pdfium && curl -L https://github.com/bblanchon/pdfium-binaries/releases/latest/download/pdfium-linux-${ARCH}.tgz | tar -xz \
    && cp lib/libpdfium.so /usr/local/lib/libpdfium.so && ldconfig

COPY --link ./include/header.h /usr/lib-pdfium/include/header.h

RUN echo "#define FFI_LIB \"libpdfium.so\"" > /usr/lib-pdfium/include/pdfium.h && gcc -P -E /usr/lib-pdfium/include/header.h >> /usr/lib-pdfium/include/pdfium.h

FROM base AS compiled

COPY ./lib/pdfium /usr/lib-pdfium/

COPY  ./include/header.h /usr/lib-pdfium/include/header.h
RUN echo "#define FFI_LIB \"libpdfium.so\"" > /usr/lib-pdfium/include/pdfium.h && gcc -P -E /usr/lib-pdfium/include/header.h >> /usr/lib-pdfium/include/pdfium.h

RUN cp /usr/lib-pdfium/lib/libpdfium.so /usr/local/lib/libpdfium.so && ldconfig

FROM precompiled AS ci

COPY --from=composer /usr/bin/composer /usr/bin/composer
RUN apt-get update && apt-get install zip -y
COPY --link . /usr/php-pdfium
