#include "libstringf.h"
#include <limits.h>
#include <stdlib.h>
int main(void)
{
	char	buf[100];
	int		ret;

	printf ("%{b}d")
	ret = snstringf(buf, 100"%s", "hello");
	stringf("%s(%d)", buf, ret);
	return (EXIT_SUCCESS);
}
