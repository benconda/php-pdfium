<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium;

use FFI\CData;
use IteratorAggregate;
use Traversable;

/**
 * @implements IteratorAggregate<int,Page>
 */
final class Document implements IteratorAggregate
{
    private readonly \FFI $ffi;

    private CData $formHandler;

    private CData $formFillInfo;

    private static $writer;

    public function __construct(
        public readonly CData $handler,
    ) {
        $this->ffi = PhpPdfium::lib()->FFI();
        $this->formFillInfo = $this->ffi->new('FPDF_FORMFILLINFO');
        $this->formFillInfo->version = 1;

        $this->formHandler = $this->ffi->FPDFDOC_InitFormFillEnvironment($this->handler, \FFI::addr($this->formFillInfo));
    }

    public function getPageCount(): int
    {
        return $this->ffi->FPDF_GetPageCount($this->handler);
    }

    public function loadPage(int $pageIndex): ?Page
    {
        $pageHandler = $this->ffi->FPDF_LoadPage($this->handler, $pageIndex);

        if (null === $pageHandler) {
            return null;
        }
        $this->ffi->FORM_OnAfterLoadPage($pageHandler, $this->formHandler);

        return new Page($this, $pageHandler, $pageIndex);
    }

    public function getPagesCount(): int
    {
        return $this->ffi->FPDF_GetPageCount($this->handler);
    }

    public function getIterator(): Traversable
    {
        for ($index = 0; $index < $this->getPagesCount(); ++$index) {
            yield $this->loadPage($index);
        }
    }

    public function forceToKillFormFocus(): bool
    {
        return (bool) $this->ffi->FORM_ForceToKillFocus($this->formHandler);
    }

    public function getFormHandler(): CData
    {
        return $this->formHandler;
    }

    public function saveAsCopy(string $filename, int $saveFlag): bool
    {
        $dir = dirname($filename);
        if (! is_dir($dir)) {
            mkdir($dir, 0777, true);
        }
        $fileWrite = $this->ffi->new('FPDF_FILEWRITE', false);
        $fileWrite->version = 1;
        self::$writer = fopen($filename, 'wb');
        // FFI callback need to be static, and can't use ($variable), to avoid segfault.
        $fileWrite->WriteBlock = self::writeDocumentCallback(...);

        $res = $this->ffi->FPDF_SaveAsCopy($this->handler, \FFI::addr($fileWrite), $saveFlag);
        fclose(self::$writer);
        \FFI::free($fileWrite);

        return (bool) $res;
    }

    private static function writeDocumentCallback(CData $handler, CData $data, int $size): bool
    {
        fwrite(self::$writer, \FFI::string($data, $size));

        return true;
    }

    public function __destruct()
    {
        $this->ffi->FPDFDOC_ExitFormFillEnvironment($this->formHandler);
        $this->ffi->FPDF_CloseDocument($this->handler);
    }
}
