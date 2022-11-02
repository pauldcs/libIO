#include "libstringf.h"
#include <stddef.h>

void	field_pad(t_iobuf *iob, size_t size)
{
	while (iob->field.width > size++)
		iob_write(iob, " ", 1);
}