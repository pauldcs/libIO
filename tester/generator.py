import sys

tests = \
[
	'"%s %s %s",             "Salut", "Mon", "Pote"',
	'"%s%d",                 "42", 42',
	'"%x%x%x",               42, 42, 42',
	'"%s%x%d%%%s",           "42", 42, 42, "42"',
	'"%x%d%x%d%x%d%x%d%x%x", 42, 42, 42, 42, 42, 42, 42, 42, 42 ,42',
	'"%x%x%x%x%x%x%x%x%x%x", 42, 42, 42, 42, 42, 42, 42, 42, 42 ,42',
	'"%s%s%s%p%x%d%%",       "", "", "", 1, 1, 1',
	'"%%%%%%%%%",            "", "", "", 1, 1, 1',
	'"%d %d",                -2147483648, 2147483647',
	'"%s%d%s%x%s%d",         "", 1, " ", 1, "", 1',
	'"%5d%5x%s",             5,5," "',
	'"%dd%dd%xx%xx",         5,5,5,5'
]

#stringf
i = 0
for test in tests:
	name = "tester/infiles/stringf_" + str(i).zfill(3) + "_test.c"
	sys.stdout = open(name, "a")
	print('#include "libstringf.h"')
	print('int main(void){        ')
	print("    stringf("+test+"); ")
	print("}                      ")
	i += 1

i = 0
for test in tests:
	name = "tester/infiles/stringf_" + str(i).zfill(3) + "_test_out.c"
	sys.stdout = open(name, "a")
	print('#include <stdio.h>   ')
	print('int main(void){      ')
	print('    printf('+test+');')
	print('    return(0);       ')
	print('}                    ')
	i += 1

#fstringf
i = 0
for test in tests:
	name = "tester/infiles/fstringf_" + str(i).zfill(3) + "_test.c"
	sys.stdout = open(name, "a")
	print('#include "libstringf.h"   ')
	print('int main(void){           ')
	print("    fstringf(1, "+test+");")
	print("}                         ")
	i += 1

i = 0
for test in tests:
	name = "tester/infiles/fstringf_" + str(i).zfill(3) + "_test_out.c"
	sys.stdout = open(name, "a")
	print('#include <stdio.h>   ')
	print('int main(void){      ')
	print('    fprintf(stdout, '+test+');')
	print('    return(0);       ')
	print('}                    ')
	i += 1

#sstringf
i = 0
for test in tests:
	name = "tester/infiles/sstringf_" + str(i).zfill(3) + "_test.c"
	sys.stdout = open(name, "a")
	print('#include "libstringf.h"     ')
	print('#include <stdio.h>          ')
	print('int main(void){             ')
	print('    char buf[128];          ')
	print("    sstringf(buf, "+test+");")
	print('    printf("%s", buf);      ')
	print("}                           ")
	i += 1

i = 0
for test in tests:
	name = "tester/infiles/sstringf_" + str(i).zfill(3) + "_test_out.c"
	sys.stdout = open(name, "a")
	print('#include <stdio.h>          ')
	print('int main(void){             ')
	print('    char buf[128];          ')
	print("    sprintf(buf, "+test+"); ")
	print('    printf("%s", buf);      ')
	print("}                           ")
	i += 1