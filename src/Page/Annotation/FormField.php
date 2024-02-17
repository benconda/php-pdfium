<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

use BenConda\PhpPdfium\Page;
use BenConda\PhpPdfium\PhpPdfium;
use FFI\CData;

class FormField extends Annotation
{
    public function __construct(Page $page, CData $handler, int $index)
    {
        parent::__construct($page, $handler, $index);

        if (AnnotationType::WIDGET !== $type = $this->getAnnotationType()) {
            throw new \LogicException("Cannot create FormField instance on no widget annotation");
        }
    }

    public function getType(): FormFieldType
    {
        $type = $this->ffi->FPDFAnnot_GetFormFieldType($this->getFormHandler(), $this->handler);

        return FormFieldType::from($type);
    }

    public function getValue(): string
    {
        return $this->getFormText('FPDFAnnot_GetFormFieldValue');
    }

    public function setValue(string $value): void
    {
        $wideChar = PhpPdfium::lib()->convertToWideString($value);

        $this->ffi->FPDFAnnot_SetStringValue(
            $this->handler,
            FormFieldDictionaryKey::VALUE->value,
            \FFI::addr($wideChar)
        );

        // Reset appearance
        $this->setAppearance(null);
    }

    public function getName(): string
    {
        return $this->getFormText('FPDFAnnot_GetFormFieldName');
    }

    public function getAlternateName(): string
    {
        return $this->getFormText('FPDFAnnot_GetFormFieldAlternateName');
    }

    public function getExportValue(): string
    {
        return $this->getFormText('FPDFAnnot_GetFormFieldExportValue');
    }

    public function isChecked()
    {
        return (bool) $this->ffi->FPDFAnnot_IsChecked($this->getFormHandler(), $this->handler);
    }

    public function getFormControlCount(): int
    {
        return $this->ffi->FPDFAnnot_GetFormControlCount($this->getFormHandler(), $this->handler);
    }

    public function getFormControlIndex(): int
    {
        return $this->ffi->FPDFAnnot_GetFormControlIndex($this->getFormHandler(), $this->handler);
    }

    private function getFormText(string $methodName): string
    {
        $formHandler = $this->getFormHandler();

        return PhpPdfium::lib()->callStringRelatedMethod(
            fn (?CData $char, int $length): int =>
                $this->ffi->{$methodName}($formHandler, $this->handler, $char, $length)
        );
    }

    private function getFormHandler(): CData
    {
        return $this->getPage()->getDocument()->getFormHandler();
    }
}
