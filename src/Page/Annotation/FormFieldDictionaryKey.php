<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

enum FormFieldDictionaryKey: string
{
    case FIELD_TYPE = 'FT';
    case PARENT = 'Parent';
    case KIDS = 'kids';
    case NAME = 'T';
    case ALTERNATE_NAME = 'TU';
    case EXPORT_VALUE = 'TM';
    case FLAGS = 'Ff';
    case VALUE = 'V';
    case DEFAULT_VALUE = 'DV';
}
