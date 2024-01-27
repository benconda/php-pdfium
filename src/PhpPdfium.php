<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium;

final class PhpPdfium
{
    private \FFI $ffi;

    private static ?self $ownInstance = null;

    public static function lib(): self
    {
        return self::$ownInstance ??= new self();
    }

    private function __construct()
    {
        // Load the library in an FFI instance
        $this->ffi = \FFI::load(dirname(__DIR__) . '/include/pdfium.h');

        // Create a new FPDF_LIBRARY_CONFIG struct / object
        $config = $this->ffi->new('FPDF_LIBRARY_CONFIG');

        // Set up the configuration
        $config->version = 2;
        $config->m_pUserFontPaths = null;
        $config->m_pIsolate = null;
        $config->m_v8EmbedderSlot = 0;

        // Initialize the library with the configuration
        $this->ffi->FPDF_InitLibraryWithConfig(\FFI::addr($config));
    }

    public function FFI(): \FFI
    {
        return $this->ffi;
    }

    public function loadDocument(string $documentPath): ?Document
    {
        # Second parameter is the document password, null if no password needed
        $docHandler = $this->ffi->FPDF_LoadDocument($documentPath, null);
        if (null === $docHandler) {
            return null;
        }

        return new Document($docHandler);
    }

    public function decodeUTF16toUT8(string $utf16String): string
    {
        $text = mb_convert_encoding($utf16String, 'UTF-8', 'UTF-16LE');

        return mb_strcut($text,0, strlen($text) -1);
    }

    public function __destruct()
    {
        $this->ffi->FPDF_DestroyLibrary();
    }
}
