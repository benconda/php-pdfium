<?php

declare(strict_types=1);

namespace BenConda\PhpPdfium;

use BenConda\Collection\CoreCollection;
use BenConda\Collection\Modifier\Filter;
use BenConda\Collection\Modifier\ModifierInterface;

/**
 * @extends CoreCollection<int, \BackedEnum>
 */
final class FlagList extends CoreCollection
{
    private function __construct(iterable $iterable, ModifierInterface $modifier = null)
    {
        parent::__construct($iterable, $modifier);
    }

    public static function fromFlags(int $flags, \BackedEnum ...$cases): self
    {
        return new self($cases, new Filter(
            callback: fn (\BackedEnum $enum) => 0 !== ($flags & $enum->value)
        ));
    }

    public function hasFlag(\BackedEnum ...$cases): bool
    {
        foreach ($this as $flag) {
            foreach ($cases as $key => $case) {
                if ($case === $flag) {
                    unset($cases[$key]);
                    break;
                }
            }
            if ([] === $cases) {
                return true;
            }
        }

        return false;
    }
}
