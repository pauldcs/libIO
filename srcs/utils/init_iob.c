#include "libIO.h"

void	init_iob(t_iobuf *iob)
{
	static char	buf[BUFFER_SIZE];
	
	iob->dst = (uint8_t *)buf;
	iob->cap = BUFFER_SIZE;
	iob->size = 0;
	iob->trunc = 0;
}