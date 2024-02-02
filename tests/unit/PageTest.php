<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Document;
use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use PHPUnit\Framework\TestCase;

final class PageTest extends TestCase
{
    private PhpPdfium $phpPdfium;

    protected function setUp(): void
    {
        $this->phpPdfium = PhpPdfium::lib();
    }

    public function testPage(): void
    {
        self::assertInstanceOf(Page::class, $this->loadDocument('cerfa_13750-05')->loadPage(0));
    }

    public function testAnnotationCount(): void
    {
        $page = $this->loadDocument('cerfa_13750-05')->loadPage(0);

        self::assertSame(112, $page->getAnnotationsCount());
    }

    private function loadDocument(string $name): Document
    {
        return $this->phpPdfium->loadDocument(dirname(__DIR__) . "/resources/$name.pdf");
    }
}
