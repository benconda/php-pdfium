<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use FFI\CData;

class Annotation
{
    protected readonly \FFI $ffi;

    public function __construct(
        protected readonly Page $page,
        protected readonly CData $handler,
        protected readonly int $index,
    ) {
        $this->ffi = PhpPdfium::lib()->FFI();
    }

    public function getAnnotationType(): AnnotationType
    {
        return AnnotationType::fromAnnotationHandler($this->handler);
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

    public function getDictionaryStringValue(string $key): string
    {
        return PhpPdfium::lib()->callStringRelatedMethod(
            fn (?CData $char, int $length) =>
                $this->ffi->FPDFAnnot_GetStringValue($this->handler, $key, $char, $length)
        );
    }

    public function getAppearance(): string
    {
        return PhpPdfium::lib()->callStringRelatedMethod(
            fn (?CData $char, int $length) =>
            $this->ffi->FPDFAnnot_GetAP($this->handler, 0, $char, $length)
        );
    }

    public function setAppearance(?string $appearance): void
    {
        if (null !== $appearance) {
            $appearance = PhpPdfium::lib()->convertToWideString($appearance);
        }

        $this->ffi->FPDFAnnot_SetAP($this->handler, 0, $appearance);
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
