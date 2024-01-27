<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

interface ImageRendererInterface
{
    public function renderPage(Renderer $renderer): ImageInterface;

    public function renderThumbnail(Renderer $renderer): ImageInterface;
}
