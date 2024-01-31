.PHONY: dump-header
dump-header:
	docker compose cp php-pdfium:/usr/lib-pdfium/include/pdfium.h ./include/pdfium.h

.PHONY: test
test:
	docker-compose run --rm php-pdfium ./vendor/bin/phpunit

.PHONY: test-ci
test-ci:
	docker-compose -f docker-compose.ci.yml build && docker-compose -f docker-compose.ci.yml run --rm php-pdfium sh -c "composer install --prefer-dist --no-progress && ls -l && ./vendor/bin/phpunit"