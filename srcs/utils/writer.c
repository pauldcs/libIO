#include "libIO.h"
#include <stddef.h>
#include <stdint.h>

void writer(t_iobuf *iob, const uint8_t *src, size_t n)
{
	size_t	ct;

	ct = 0;
	while (ct + iob->size < iob->cap && ct < n)
	{
		iob->dst[iob->size + ct] = src[ct];
		ct++;
	}
	iob->size += ct;
	iob->trunc += n - ct;
}