<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Page;
use PHPUnit\Framework\TestCase;

final class PageTest extends TestCase
{
    use TestDocumentLoaderHelper;

    public function testPage(): void
    {
        self::assertInstanceOf(Page::class, $this->loadDocument('cerfa_13750-05')->loadPage(0));
    }

    public function testAnnotationCount(): void
    {
        $page = $this->loadDocument('cerfa_13750-05')->loadPage(0);

        self::assertSame(112, $page->getAnnotationsCount());
    }
}
