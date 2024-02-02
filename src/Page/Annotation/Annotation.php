<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use FFI\CData;

class Annotation
{
    private readonly \FFI $ffi;

    public function __construct(
        private readonly Page $page,
        private readonly CData $handler,
        private readonly int $index,
    ) {
        $this->ffi = PhpPdfium::lib()->FFI();
    }

    public function getAnnotationType(): AnnotationType
    {
        $type = $this->ffi->FPDFAnnot_GetSubtype($this->handler);

        return AnnotationType::from($type);
    }

    public function getPage(): Page
    {
        return $this->page;
    }

    public function getHandler(): CData
    {
        return $this->handler;
    }

    public function getIndex(): int
    {
        return $this->index;
    }

    public function close(): void
    {
        $this->ffi->FPDFPage_CloseAnnot($this->handler);
    }

    public function __destruct()
    {
        $this->close();
    }
}
