<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium\Page\Annotation;

enum AnnotationType: int
{
    case UNKNOWN = 0;
    case TEXT = 1;
    case LINK = 2;
    case FREETEXT = 3;
    case LINE = 4;
    case SQUARE = 5;
    case CIRCLE = 6;
    case POLYGON = 7;
    case POLYLINE = 8;
    case HIGHLIGHT = 9;
    case UNDERLINE = 10;
    case SQUIGGLY = 11;
    case STRIKEOUT = 12;
    case STAMP = 13;
    case CARET = 14;
    case INK = 15;
    case POPUP = 16;
    case FILEATTACHMENT = 17;
    case SOUND = 18;
    case MOVIE = 19;
    case WIDGET = 20;
    case SCREEN = 21;
    case PRINTERMARK = 22;
    case TRAPNET = 23;
    case WATERMARK = 24;
    case THREED = 25;
    case RICHMEDIA = 26;
    case XFAWIDGET = 27;
    case REDACT = 28;

}
