#include "libIO.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

size_t	sstringf(char *str, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	iob.dst = (uint8_t *)str;
	iob.cap = BUFFER_SIZE - 1;
	iob.size = 0;
	va_start(ap, fmt);
	vsnstringf(&iob, fmt, &ap);
	iob.dst[iob.size] = '\0';
	va_end(ap);
	return (iob.size);
}