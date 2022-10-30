#include "libIO.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char	*cnstringf(size_t n, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	iob.dst = malloc(n);
	if (!iob.dst)
		return (NULL);
	iob.cap = n - 1;
	iob.size = 0;
	va_start(ap, fmt);
	vsnstringf(&iob, fmt, &ap);
	iob.dst[iob.size] = '\0';
	va_end(ap);
	return ((char *)iob.dst);
}