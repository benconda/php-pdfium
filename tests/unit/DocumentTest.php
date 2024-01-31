<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Document;
use BenConda\PhpPdfium\DocumentSaveFlags;
use BenConda\PhpPdfium\Page\VipsImageRenderer;
use BenConda\PhpPdfium\PhpPdfium;
use PHPUnit\Framework\TestCase;

final class DocumentTest extends TestCase
{
    private PhpPdfium $phpPdfium;

    protected function setUp(): void
    {
        $this->phpPdfium = PhpPdfium::lib();
    }

    public function testDocument(): void
    {
        self::assertInstanceOf(Document::class, $this->loadDocument('cerfa_13750-05'));
    }

    public function testPageCount(): void
    {
        self::assertSame(36, $this->loadDocument('notice')->getPageCount());
    }

    public function testRenderAllPagesIterable(): void
    {
        $notice = $this->loadDocument('notice');
        $renderer = new VipsImageRenderer();
        $directory = dirname(__DIR__) . '/resources/generated/notice';
        mkdir($directory, recursive: true);
        foreach ($notice as $page) {
            $page->getRenderer()->render($renderer)->save($directory . "/{$page->getNumber()}.png");
        }
        $files = scandir($directory);
        // 38 here because scandir() return "." and ".." folders in list
        self::assertCount(38, $files);
    }

    public function testSaveFlattenedCopy(): void
    {
        $cerfaDoc = $this->loadDocument('cerfa_13750-05');
        $firstPage = $cerfaDoc->loadPage(0);
        $annotationCount = $firstPage->getAnnotationsCount();
        self::assertSame(112, $annotationCount);
        $firstPage->flatten();
        $res = $cerfaDoc->saveAsCopy(dirname(__DIR__) . '/resources/generated/flattened-cerfa.pdf', DocumentSaveFlags::NO_INCREMENTAL->value);
        self::assertTrue($res);
        // Force document memory release
        $cerfaDoc = null;

        $newCerfa = $this->loadDocument('generated/flattened-cerfa');
        $newCerfaAnnotationCount = $newCerfa->loadPage(0)->getAnnotationsCount();
        // Then new doc is well flattened (no more annotation)
        self::assertSame(0, $newCerfaAnnotationCount);
    }

    private function loadDocument(string $name): Document
    {
        return $this->phpPdfium->loadDocument(dirname(__DIR__) . "/resources/$name.pdf");
    }
}
