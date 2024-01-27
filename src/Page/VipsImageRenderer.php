<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

use Jcupitt\Vips\BandFormat;
use Jcupitt\Vips\FFI;
use Jcupitt\Vips\Image;

final readonly class VipsImageRenderer implements ImageRendererInterface
{
    public function renderPage(Renderer $renderer): ImageInterface
    {
        //Config::setLogger(new DebugLogger());
        $pointer = FFI::vips()->vips_image_new_from_memory(
            $renderer->getRawBitmapBuffer(),
            $renderer->size(),
            $renderer->width,
            $renderer->height,
            $renderer::BANDS,
            BandFormat::UCHAR
        );

        $image = new Image($pointer);

        // We need to swap band order (blue <-> red), pdfium image are BGRA, libvips expect RGBA
        $b = $image[0];
        $r = $image[2];
        $image[0] = $r;
        $image[2] = $b;

        return new VipsImage($renderer, $image);
    }

    public function renderThumbnail(Renderer $renderer): ImageInterface
    {
        // TODO: Implement renderThumbnail() method.
    }
}
