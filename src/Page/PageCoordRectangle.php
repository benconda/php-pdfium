<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page;

use FFI\CData;

/**
 * Represents a rectangle in page coordinate system
 *
 * (0,0) is bottom left of the page.
 */
final readonly class PageCoordRectangle
{
    public function __construct(
        public float $left,
        public float $top,
        public float $right,
        public float $bottom,
    ) {
    }

    public static function fromPdfium(CData $rect)
    {
        return new self(
            $rect->left,
            $rect->top,
            $rect->right,
            $rect->bottom,
        );
    }

    public function writeToPdfium(CData $rect): void
    {
        $rect->left = $this->left;
        $rect->top = $this->top;
        $rect->right = $this->right;
        $rect->bottom = $this->bottom;
    }

    public function translate(float $x, float $y): self
    {
        return new self(
            $this->left + $x,
            $this->top + $y,
            $this->right + $x,
            $this->bottom + $y
        );
    }
}
