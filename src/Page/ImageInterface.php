<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

interface ImageInterface
{
    public function save(string $path);

    public function stream(): iterable;
}
