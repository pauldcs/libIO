import sys

tests = [
	'"%s %s %s", "Salut", "Mon", "Pote"',
	'"%s%d", "42", 42',
	'"%x%x%x", 42, 42, 42',
	'"%s%x%d%%%s", "42", 42, 42, "42"',
	'"%x%d%x%d%x%d%x%d%x%x", 42, 42, 42, 42, 42, 42, 42, 42, 42 ,42',
	'"%x%x%x%x%x%x%x%x%x%x", 42, 42, 42, 42, 42, 42, 42, 42, 42 ,42',
	'"%s%s%s%p%x%d%%", "", "", "", 1, 1, 1',
	'"%%%%%%%%%", "", "", "", 1, 1, 1',
	'"%d %d", -2147483648, 2147483647',
	'""',
]

i = 0
for test in tests:
	name = "tester/infiles/stringf_" + str(i) + "_in.c"
	sys.stdout = open(name, "a")
	print('#include "libstringf.h"')
	print('int main(void){')
	print("    stringf("+test+");")
	print("}")
	name = "tester/infiles/stringf_" + str(i) + "_in_out.c"
	sys.stdout = open(name, "a")
	print('#include "stdio.h"')
	print('int main(void){')
	print("    printf("+test+");")
	print("}")
	i += 1

