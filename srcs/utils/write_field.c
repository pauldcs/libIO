#include "libstringf.h"
#include <stddef.h>
#include <stdint.h>

void	write_field(t_iobuf *iob, size_t n)
{
	size_t	ct;

	if (n >= (size_t)iob->fwidth)
		return ;
	ct = 0;
	n = iob->fwidth - n;
	while (ct + iob->size < iob->cap && ct < n)
	{
		iob->dst[iob->size + ct] = ' ';
		ct++;
	}
	iob->size += ct;
	iob->trunc += n - ct;
}