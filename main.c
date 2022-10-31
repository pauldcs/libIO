#include "libstringf.h"
#include <limits.h>
#include <unistd.h>
int main (void)
{
	fstringf(1, "%d\n", -2);
	return (0);
}
