#include "libIO.h"
#include <stddef.h>
#include <string.h>

void	__str(t_iobuf *iob, const char *s)
{
	if (s)
		writer(iob, (uint8_t *)s, strlen(s));
}