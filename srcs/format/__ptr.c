#include "libIO.h"
#include <stdint.h>
#include <stddef.h>

void	__ptr(t_iobuf *iob, const uint64_t *p)
{
	uint64_t		ptr;
	static char		hex[18];
	int				i;

	i = 18;
	if (p == 0)
		hex[--i] = '0';
	ptr = (uint64_t)p;
	while (ptr && i)
	{
		hex[--i] = "0123456789abcdef"[ptr & 0xf];
		ptr >>= 4;
	}
	hex[--i] = 'x';
	hex[--i] = '0';
	writer(
		iob,
		(uint8_t *)&hex[i],
		18 - i);
}