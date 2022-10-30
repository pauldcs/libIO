#include "libIO.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

size_t	fstringf(int fd, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	init_iob(&iob);
	va_start(ap, fmt);
	vsnstringf(&iob, fmt, &ap);
	write_all(fd, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}