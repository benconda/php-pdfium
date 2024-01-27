<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

use Jcupitt\Vips\Image;
use Jcupitt\Vips\TargetCustom;

final readonly class VipsImage implements ImageInterface
{
    public function __construct(
        private Renderer $renderer,
        private Image $image
    ) {
    }

    public function save(string $path)
    {
        $this->image->writeToFile($path);
    }

    public function stream(): iterable
    {
        $target = new TargetCustom();

        return [];
    }
}
