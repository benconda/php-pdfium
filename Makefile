.PHONY: dump-header
dump-header:
	 docker compose up -d php-pdfium --remove-orphans --build && docker compose cp php-pdfium:/usr/lib-pdfium/include/pdfium.h ./include/pdfium.h

# Use this only to get include headers from precompiled pdfium lib
.PHONY: dump-lib-headers
dump-lib-headers: build
	mkdir -p ./lib/pdfium && docker compose cp php-pdfium:/usr/lib-pdfium/include ./lib/pdfium/include/.

.PHONY: test
test:
	docker compose run --rm php-pdfium ./vendor/bin/phpunit

.PHONY: test-ci
test-ci:
	docker compose -f compose.ci.yml run --build --rm php-pdfium sh -c "composer install --prefer-dist --no-progress && ls -l && ./vendor/bin/phpunit"

.PHONY: build
build:
	docker buildx bake php-pdfium

.PHONY: build-pdfium-lib
build-pdfium-lib:
	docker buildx bake pdfium-lib && docker compose up pdfium-lib
