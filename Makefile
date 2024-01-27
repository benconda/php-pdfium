.PHONY: dump-header
dump-header:
	docker compose cp php-pdfium:/usr/lib-pdfium/include/pdfium.h ./include/pdfium.h

.PHONY: test
test:
	docker-compose run --rm php-pdfium ./vendor/bin/phpunit