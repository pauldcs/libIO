#include "libstringf.h"
#include <stddef.h>
#include <stdint.h>

void	write_field(t_iobuf *iob, size_t n)
{
	size_t	ct;

	if (n < (size_t)iob->fwidth)
	{
		ct = 0;
		while (ct + iob->size < iob->cap && ct < iob->fwidth - n)
		{
			iob->dst[iob->size + ct] = ' ';
			ct++;
		}
		iob->size += ct;
		iob->trunc += iob->fwidth - n - ct;
	}
}