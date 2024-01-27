<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

use BenConda\PhpPdfium\PhpPdfium;
use FFI\CData;

final class FormField
{

    protected readonly \FFI $ffi;

    public function __construct(private Annotation $annotation)
    {
        if (AnnotationType::WIDGET !== $annotation->getAnnotationType()) {
            throw new \LogicException("Wrong form field type");
        }
        $this->ffi = PhpPdfium::lib()->FFI();
    }

    public function getType(): FormFieldType
    {
        $type = $this->ffi->FPDFAnnot_GetFormFieldType($this->getFormHandler(), $this->annotation->getHandler());
        return FormFieldType::from($type);
    }

    public function getValue(): string
    {
        return $this->getFormText('FPDFAnnot_GetFormFieldValue');
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
        return (bool) $this->ffi->FPDFAnnot_IsChecked($this->getFormHandler(), $this->annotation->getHandler());
    }

    public function getFormControlCount(): int
    {
        return $this->ffi->FPDFAnnot_GetFormControlCount($this->getFormHandler(), $this->annotation->getHandler());
    }

    public function getFormControlIndex(): int
    {
        return $this->ffi->FPDFAnnot_GetFormControlIndex($this->getFormHandler(), $this->annotation->getHandler());
    }

    private function getFormText(string $methodName): string
    {
        $formHandler = $this->getFormHandler();
        $length =  $this->ffi->{$methodName}($formHandler, $this->annotation->getHandler(), null, 0);
        $buffer = $this->ffi->new("FPDF_WCHAR");
        $pointer = \FFI::addr($buffer);
        $this->ffi->{$methodName}($formHandler, $this->annotation->getHandler(), $pointer, $length);
        $str = \FFI::string($pointer, $length);

        return PhpPdfium::lib()->decodeUTF16toUT8($str);
    }

    private function getFormHandler(): CData
    {
        return $this->annotation->getPage()->getDocument()->getFormHandler();
    }
}