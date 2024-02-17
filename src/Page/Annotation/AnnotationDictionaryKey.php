<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

enum AnnotationDictionaryKey: string
{
    case A = 'A';
    case AP = 'AP';
    case AS = 'AS';
    case BORDER = 'Border';
    case BS = 'BS';
    case C = 'C';
    case CA = 'CA';
    case CONTENTS = 'Contents';
    case F = 'F';
    case M = 'M';
    case NM = 'NM';
    case OC = 'OC';
    case PAGE = 'Page';
    case POPUP = 'Popup';
}
