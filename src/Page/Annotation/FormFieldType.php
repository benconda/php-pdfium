<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

enum FormFieldType: int
{
    case UNKNOWN = 0;
    case PUSHBUTTON = 1;
    case CHECKBOX = 2;
    case RADIOBUTTON = 3;
    case COMBOBOX = 4;
    case LISTBOX = 5;
    case TEXTFIELD = 6;
    case SIGNATURE = 7;
}