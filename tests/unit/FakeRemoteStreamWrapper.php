<?php

declare(strict_types=1);

namespace BenCondaTest\PhpPdfium;

/**
 * A custom PHP stream wrapper that serves local files under a custom protocol.
 * This simulates remote stream behavior (like S3) for testing loadDocumentFromResource()
 * without requiring an external service.
 *
 * Usage: stream_wrapper_register('fake-remote', FakeRemoteStreamWrapper::class);
 *        fopen('fake-remote:///path/to/local/file.pdf', 'r');
 */
class FakeRemoteStreamWrapper
{
    /**
     * @var resource|null
     */
    private $handle;

    public function stream_open(string $path, string $mode, int $options, ?string &$opened_path): bool
    {
        $localPath = substr($path, strlen('fake-remote://'));
        $this->handle = fopen($localPath, $mode);

        return false !== $this->handle;
    }

    public function stream_read(int $count): string|false
    {
        return fread($this->handle, $count);
    }

    public function stream_seek(int $offset, int $whence = SEEK_SET): bool
    {
        return 0 === fseek($this->handle, $offset, $whence);
    }

    public function stream_tell(): int|false
    {
        return ftell($this->handle);
    }

    public function stream_eof(): bool
    {
        return feof($this->handle);
    }

    public function stream_stat(): array|false
    {
        return fstat($this->handle);
    }

    public function stream_close(): void
    {
        fclose($this->handle);
    }

    public function url_stat(string $path, int $flags): array|false
    {
        $localPath = substr($path, strlen('fake-remote://'));

        return stat($localPath);
    }
}
