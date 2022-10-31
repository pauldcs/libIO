import sys

test_list = [
	'"%d", INT_MAX',
	'"%d", INT_MIN',
	'"%d", 0',
	'"%d", -0',
	'"%d", 1',
	'"%d", -1',
	'"%d", LONG_MAX',
	'"%d", LONG_LIN',
	'"%d", UINT_MAX',
	'"%d", UINT_MIN',
	'"%d", ULONG_MAX',
	'"%d", 9223372036854775807LL',
	'"%d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)',
	'"%x", INT_MAX',
	'"%x", INT_MIN',
	'"%x", 0',
	'"%x", -0',
	'"%x", 1',
	'"%x", -1',
	'"%x", LONG_MAX',
	'"%x", LONG_LIN',
	'"%x", UINT_MAX',
	'"%x", UINT_MIN',
	'"%x", ULONG_MAX',
	'"%x", 9223372036854775807LL',
	'"%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)',
	'"%s", ""',
	'" %s", ""',
	'"%s ", ""',
	'"%s ", "-"',
	'"%s %s", "", "-"',
	'"%s %s %s %s", "", "-", "", "4"',
	'"%s %s %s %s", NULL, "-", NULL, "4"'
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
	stringf("""+test+""");
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
	printf("""+test+""");
	return (0);
}
""")