#include "libIO.h"
#include <stdint.h>
#include <stddef.h>

void	__hex(t_iobuf *iob, const uint64_t n)
{
	uint64_t	tmp;
	static char	bytes[16];
	int			i;

	i = 16;
	if (n == 0)
		bytes[--i] = '0';
	else
	{
		tmp = n;
		while (i && tmp)
		{
			bytes[--i] = "0123456789abcdef"[tmp & 0xf];
			tmp >>= 4;
		}
	}
	writer(
		iob,
		(uint8_t *)&bytes[i],
		16 - i);
}