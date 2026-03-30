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

    private function loadDocumentFromResource(string $name): Document
    {
        $path = dirname(__DIR__) . "/resources/$name.pdf";
        $resource = fopen($path, 'r');

        return PhpPdfium::lib()
            ->loadDocumentFromResource($resource);
    }

    private function loadDocumentFromStreamWrapper(string $name): Document
    {
        if (! in_array('fake-remote', stream_get_wrappers(), true)) {
            stream_wrapper_register('fake-remote', FakeRemoteStreamWrapper::class);
        }

        $path = dirname(__DIR__) . "/resources/$name.pdf";
        $resource = fopen("fake-remote://$path", 'r');

        return PhpPdfium::lib()
            ->loadDocumentFromResource($resource);
    }
}
