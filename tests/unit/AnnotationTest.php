<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

use BenConda\PhpPdfium\DocumentSaveFlags;
use BenConda\PhpPdfium\Page\Annotation\Annotation;
use BenConda\PhpPdfium\Page\Annotation\FormField;
use BenConda\PhpPdfium\Page\Annotation\FormFieldType;
use BenConda\PhpPdfium\Page\PageCoordRectangle;
use PHPUnit\Framework\TestCase;

final class AnnotationTest extends TestCase
{
    use TestDocumentLoaderHelper;

    public function testGetAnnotation(): void
    {
        $cerfaDoc = $this->loadDocument('cerfa_13750-05');
        $firstPage = $cerfaDoc->loadPage(0);
        $annot = $firstPage->loadAnnotation(13);
        self::assertInstanceOf(Annotation::class, $annot);
        $rect = $annot->getRectangle();
        self::assertInstanceOf(PageCoordRectangle::class, $rect);
    }

    public function testMoveAnnotation(): void
    {
        $cerfaDoc = $this->loadDocument('cerfa_13750-05');
        $firstPage = $cerfaDoc->loadPage(0);
        $annot = $firstPage->loadAnnotation(13);
        self::assertInstanceOf(FormField::class, $annot);
        $rect = $annot->getRectangle();
        self::assertInstanceOf(PageCoordRectangle::class, $rect);
        $annot->setRectangle($translatedRect = $rect->translate(10, 10));
        $newRect = $annot->getRectangle();
        self::assertEquals($newRect, $translatedRect);
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
}
