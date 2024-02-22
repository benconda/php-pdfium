<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Document;
use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use Jcupitt\Vips\Image;
use PHPUnit\Framework\TestCase;

final class PhpPfiumTest extends TestCase
{
    use TestDocumentLoaderHelper;

    private PhpPdfium $phpPdfium;

    protected function setUp(): void
    {
        $this->phpPdfium = PhpPdfium::lib();
    }

    public function testInit(): void
    {
        self::assertInstanceOf(PhpPdfium::class, $this->phpPdfium);
    }

    public function testDocumentLoading(): void
    {
        $document = $this->loadDocument('cerfa_13750-05');
        self::assertInstanceOf(Document::class, $document);
        self::assertSame(1, $document->getPageCount());
    }

    public function testPageLoading(): void
    {
        $document = $this->loadDocument('cerfa_13750-05');
        $page = $document->loadPage(0);
        self::assertInstanceOf(Page::class, $page);
        self::assertSame(595, $page->getWidth());
        self::assertSame(841, $page->getHeight());
    }

    public function testFlattenRendering(): void
    {
        $document = $this->loadDocument('cerfa_13750-05');
        $page = $document->loadPage(0);
        $imageRenderer = new Page\VipsImageRenderer();
        $targetDir = dirname(__DIR__) . '/resources/generated';
        mkdir($targetDir);
        $targetFile = $targetDir . '/0.png';
        $bitmap = $page->flatten()->getBitmap();
        $imageRenderer->renderImage($bitmap)->save($targetFile);
        self::assertStringNotEqualsFile($targetFile, '');
        $renderedImage = Image::newFromFile($targetFile);
        self::assertSame(595, $renderedImage->width);
        self::assertSame(841, $renderedImage->height);
    }
}
