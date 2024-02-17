<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use FFI\CData;

final class PageBitmap
{
    public const BANDS = 4;

    private readonly \FFI $ffi;

    public readonly int $width;

    public readonly int $height;

    private readonly CData $bitmap;

    public function __construct(
        private readonly Page $page,
        ?int $width = null,
        ?int $height = null,
        private ?int $x = 0,
        private ?int $y = 0
    ) {
        $this->ffi = PhpPdfium::lib()->FFI();
        $pageWidth = $this->page->getWidth();
        $pageHeight = $this->page->getHeight();

        if (null !== $width) {
            $this->width = $width;
            if (null === $height) {
                $this->height = intval(round($pageHeight * $width / $pageWidth));
            }
        }

        if (null !== $height) {
            $this->height = $height;
            if (null === $width) {
                $this->width = intval(round($pageWidth * $height / $pageHeight));
            }
        }

        if (null === $width && null === $height) {
            $this->height = $pageHeight;
            $this->width = $pageWidth;
        }
    }

    public function getHandler(): CData
    {
        // Initialize empty bitmap on the given size
        $this->bitmap = $this->ffi->FPDFBitmap_Create($this->width, $this->height, 0);
        // Fill it in white
        $this->ffi->FPDFBitmap_FillRect($this->bitmap, 0, 0, $this->width, $this->height, 0xFFFFFF);
        // Render in bitmap
        $this->ffi->FPDF_RenderPageBitmap($this->bitmap, $this->page->getHandler(), $this->x, $this->y, $this->width, $this->height, 0, 0x800);

        return $this->bitmap;
    }

    public function getBuffer(): CData
    {
        if (! isset($this->bitmap)) {
            $this->getHandler();
        }

        return $this->ffi->FPDFBitmap_GetBuffer($this->bitmap);
    }

    public function size(): int
    {
        return $this->width * $this->height * self::BANDS;
    }

    public function __destruct()
    {
        if (isset($this->bitmap)) {
            $this->ffi->FPDFBitmap_Destroy($this->bitmap);
        }
    }
}
