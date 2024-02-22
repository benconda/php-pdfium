<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Document;
use BenConda\PhpPdfium\PhpPdfium;

trait TestDocumentLoaderHelper
{
    private function loadDocument(string $name): Document
    {
        return PhpPdfium::lib()
            ->loadDocument(dirname(__DIR__) . "/resources/$name.pdf");
    }
}
