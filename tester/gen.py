import sys

test_list = [
	'"%d", INT_MAX',
	'"%d", INT_MIN',
	'"%d", 0',
	'"%d", -0',
	'"%5d", 1',
	'"%6d", -1',
	'"%7d", LONG_MAX',
	'"%8d", LONG_LIN',
	'"%9d", UINT_MAX',
	'"%10d", UINT_MIN',
	'"%11d", ULONG_MAX',
	'"%12d", 9223372036854775807LL',
	'"%1d %d %2d %d %3d %d %5d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)',
	'"%10x", INT_MAX',
	'"%0x", INT_MIN',
	'"%x", 0',
	'"%2x", -0',
	'"% x", 1',
	'"%3 x", -1',
	'"%10x", LONG_MAX',
	'"%10x", LONG_LIN',
	'"%x", UINT_MAX',
	'"%x", UINT_MIN',
	'"%x", ULONG_MAX',
	'"%x", 9223372036854775807LL',
	'"%1x %x %2x %x %3x %x %4x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)',
	'"%s", ""',
	'" %s", ""',
	'"%s ", ""',
	'"%s ", "-"',
	'"%s %s", "", "-"',
	'"%4t %s %4 s%s% %5s", NULL, "-", NULL, "4"',
	'"%1s %2s %3s %s", "", "-", "", "4"',
	'"%s %4s %s %5s", NULL, "-", NULL, "4"',
]

#stringf
for test in test_list:
	test_name = "tester/infiles/" + "stringf" + "_" \
			+ str(test_list.index(test)).zfill(3)   \
			+ "_test.c"
	with open(test_name, 'w') as f:
		f.write(
"""
#include "libstringf.h"
#include <limits.h>
#include <stdlib.h>
int main(void)
{
	stringf(" (ret: %d)", stringf("""+test+"""));
	return (0);
}
""")

for test in test_list:
	test_name = "tester/infiles/" + "stringf" + "_" \
			+ str(test_list.index(test)).zfill(3)   \
			+ "_test_out.c"
	with open(test_name, 'w') as f:
		f.write(
"""
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main(void)
{
	printf(" (ret: %d)", printf("""+test+"""));
	return (0);
}
""")