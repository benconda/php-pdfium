<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

interface ImageRendererInterface
{
    public function renderImage(PageBitmap $bitmap): ImageInterface;
}
