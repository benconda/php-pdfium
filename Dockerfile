FROM php:8.2-cli-bookworm as base

ADD https://github.com/mlocati/docker-php-extension-installer/releases/latest/download/install-php-extensions /usr/local/bin/

RUN chmod +x /usr/local/bin/install-php-extensions && \
    install-php-extensions ffi

RUN mkdir -p /usr/lib-pdfium && cd /usr/lib-pdfium && curl -L https://github.com/bblanchon/pdfium-binaries/releases/latest/download/pdfium-linux-arm64.tgz | tar -xz \
    && cp lib/libpdfium.so /usr/local/lib/libpdfium.so && ldconfig

# Test libvips integration
RUN mkdir -p /usr/lib-vips && cd /usr/lib-vips && curl -L https://github.com/lovell/sharp-libvips/releases/download/v8.16.1/libvips-8.16.1-linux-arm64v8.tar.gz | tar -xz \
    && cp lib/libvips-cpp.so.* /usr/local/lib/libvips.so.42  && ldconfig

ENV VIPSHOME=/usr/local

COPY --link ./include/header.h /usr/lib-pdfium/include/header.h

RUN echo "#define FFI_LIB \"libpdfium.so\"" > /usr/lib-pdfium/include/pdfium.h && gcc -P -E /usr/lib-pdfium/include/header.h >> /usr/lib-pdfium/include/pdfium.h

WORKDIR /usr/php-pdfium

FROM base as ci

COPY --from=composer /usr/bin/composer /usr/bin/composer
RUN apt-get update && apt-get install zip -y
COPY --link . /usr/php-pdfium