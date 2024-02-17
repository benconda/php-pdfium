<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

use BenConda\PhpPdfium\Page;
use FFI\CData;

final class AnnotationFactory
{
    public static function create(Page $page, CData $handler, int $index)
    {
        $annotationType = AnnotationType::fromAnnotationHandler($handler);

        return match ($annotationType) {
            AnnotationType::WIDGET => new FormField($page, $handler, $index),
            default => new Annotation($page, $handler, $index)
        };
    }
}
