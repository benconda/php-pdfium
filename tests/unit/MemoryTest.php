<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use PHPUnit\Framework\TestCase;

final class MemoryTest extends TestCase
{
    use TestDocumentLoaderHelper;

    public function testGarbageCollectionDoesNotCauseSegfault(): void
    {
        // 1. Load document from resource
        $document = $this->loadDocumentFromResource('cerfa_13750-05');

        // 2. Force garbage collection.
        // If the callback/struct is held by FFI internal structures, this is safe.
        gc_collect_cycles();

        // 3. Perform an operation that requires reading from the file.
        $page = $document->loadPage(0);
        $width = $page->getWidth();

        self::assertGreaterThan(0, $width);
    }

    public function testNoMemoryLeakWhenLoadingMultipleDocumentsFromResource(): void
    {
        $documents = ['cerfa_13750-05', 'notice', 'version4pdf'];
        $iterations = 50;

        $loadAndDiscard = function () use ($documents, $iterations): void {
            for ($i = 0; $i < $iterations; $i++) {
                $doc = $this->loadDocumentFromResource($documents[$i % count($documents)]);
                $page = $doc->loadPage(0);
                $page->getWidth();
                unset($page, $doc);
            }
        };

        // Phase 1: warm up to stabilize PHP internals (FFI, autoloader, allocator)
        $loadAndDiscard();
        gc_collect_cycles();

        // Phase 2: measure — any growth here indicates a real leak
        $memoryBefore = memory_get_usage();
        $loadAndDiscard();
        gc_collect_cycles();
        $memoryAfter = memory_get_usage();

        $leaked = $memoryAfter - $memoryBefore;

        self::assertLessThan(256 * 1024, $leaked, sprintf('Memory leaked: %d bytes after %d iterations', $leaked, $iterations));
    }
}
