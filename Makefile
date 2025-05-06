.PHONY: dump-header
dump-header: build
	docker compose cp php-pdfium:/usr/lib-pdfium/include/pdfium.h ./include/pdfium.h

.PHONY: dump-lib-headers
dump-lib-headers: build
	mkdir -p ./lib-headers/pdfium && docker compose cp php-pdfium:/usr/lib-pdfium/include ./lib-headers/pdfium/.

.PHONY: test
test:
	docker-compose run --rm php-pdfium ./vendor/bin/phpunit

.PHONY: test-ci
test-ci:
	docker buildx bake -f docker-compose.ci.yml && docker compose -f docker-compose.ci.yml run --rm php-pdfium sh -c "composer install --prefer-dist --no-progress && ls -l && ./vendor/bin/phpunit"

.PHONY: build
build:
	docker buildx bake