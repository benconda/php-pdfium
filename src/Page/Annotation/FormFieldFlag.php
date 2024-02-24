<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

enum FormFieldFlag: int
{
    // Common flags
    case READ_ONLY = (1 << 0);
    case REQUIRED = (1 << 1);
    case NO_EXPORT = (1 << 2);

    // TextFieldFlags
    case MULTILINE = (1 << 13);
    case PASSWORD = (1 << 14);
    case FILE_SELECT = (1 << 21);
    case DO_NOT_SPELL_CHECK = (1 << 23);
    case DO_NOT_SCROLL = (1 << 24);
    case COMB = (1 << 25);
    case RICH_TEXT = (1 << 26);
}
