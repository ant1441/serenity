#include "FullDevice.h"
#include "Limits.h"
#include "sys-errno.h"
#include <AK/StdLib.h>
#include <AK/kstdio.h>

FullDevice::FullDevice()
{
}

FullDevice::~FullDevice()
{
}

Unix::ssize_t FullDevice::read(byte* buffer, Unix::size_t bufferSize)
{
    kprintf("FullDevice: read from full\n");
    Unix::size_t count = min(GoodBufferSize, bufferSize);
    memset(buffer, 0, count);
    return count;
}

Unix::ssize_t FullDevice::write(const byte*, Unix::size_t bufferSize)
{
    if (bufferSize == 0)
        return 0;
    return -ENOSPC;
}

