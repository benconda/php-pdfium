<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\Document;
use BenConda\PhpPdfium\DocumentSaveFlags;
use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\Page\Annotation\FormField;
use BenConda\PhpPdfium\Page\Annotation\FormFieldType;
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

    public function testFormTextFieldFilling(): void
    {
        $doc = $this->loadDocument('cerfa_13750-05');
        $page = $doc->loadPage(0);
        foreach ($page->getFormFieldsIterator() as $field) {
            if (FormFieldType::TEXTFIELD === $field->getType() && $field->getValue() === 'Text in the form') {
                $field->setValue('New value é@oh');
                $index = $field->getIndex();
                break;
            }
        }
        $page->generateContent();

        $doc->saveAsCopy(dirname(__DIR__) . '/resources/generated/cerfa_text_changed.pdf', DocumentSaveFlags::NO_INCREMENTAL->value);
        unset($page, $doc);
        $newDoc = $this->loadDocument('generated/cerfa_text_changed');
        $newDocField = $newDoc->loadPage(0)->loadAnnotation($index);
        self::assertInstanceOf(FormField::class, $newDocField);
        self::assertSame('New value é@oh', $newDocField->getValue());
    }

    private function loadDocument(string $name): Document
    {
        return $this->phpPdfium->loadDocument(dirname(__DIR__) . "/resources/$name.pdf");
    }
}
