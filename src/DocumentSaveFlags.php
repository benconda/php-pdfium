<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium;

enum DocumentSaveFlags: int
{
    // Use incremental if you want to keep previous version changes
    case INCREMENTAL = 1;

    // Use no incremental to skip versioning (useful for flatten for example, or changing file password protection)
    case NO_INCREMENTAL = 2;

    // Remove document security (password and permission)
    case REMOVE_SECURITY = 3;
}
