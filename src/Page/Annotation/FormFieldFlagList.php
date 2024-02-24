<?php

namespace BenConda\PhpPdfium\Page\Annotation;

class FormFieldFlagList
{

    /**
     * @param int $flags
     */
    public function __construct(
        public int $flags,
    )
    {
    }

    public function hasFlag(FormFieldFlag $flag): bool
    {
        return ($this->flags & $flag->value) === $flag->value;
    }

    /**
     * @return list<FormFieldFlag>
     */
    public function list(): array
    {
        if ($this->flags === 0) {
            return [];
        }

        $flags = [];
        foreach (FormFieldFlag::cases() as $flag) {
            if ($this->hasFlag($flag)) {
                $flags[] = $flag;
            }
        }

        return $flags;
    }

    public function withFlag(FormFieldFlag $flag): self
    {
        return new self($this->flags | $flag->value);
    }

    public function withoutFlag(FormFieldFlag $flag): self
    {
        return new self($this->flags & ~$flag->value);
    }
}