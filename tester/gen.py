test_list = \
[
	['"%d", INT_MAX',   
		"2147483647(10)"], 
	['"%d", INT_MIN',    
		"-2147483648(11)"], 
	['"%6d", 0', 
		"     0(6)"],   
	['"%d", -0', 
		"0(1)"],    
	['"%x", INT_MAX',
		"7fffffff(8)"], 
	['"%x", INT_MIN', 
		"80000000(8)"],  
	['"%2x", 0', 
		" 0(2)"],   
	['"%x", -0', 
		"0(1)",],   
	['"%x", 1', 
		"1(1)"],
	['"%3x", -1',       
		"ffffffff(8)"],
	['"%3s", ""', 
		"   (3)"],  
	['"%1s ", "-"', 
		"- (2)"],   
	['"%s %s", "", "-"', 
		 " -(2)"],       
	['"%t %s %4  s%s% %s", "1", "2", "3"', 
		"%t 1 %4  s2% 3(14)"]              
]

#stringf
for test in test_list:
	infile_name = "tester/infiles/" + "stringf" + "_" \
			+ str(test_list.index(test)).zfill(3)     \
			+ "_test.c"
	with open(infile_name, 'w') as infile:
		infile.write(
	"""
		#include "libstringf.h"
		#include <limits.h>
		#include <stdlib.h>
		int main(void)
		{
			char	*buf;
			int		ret;

			ret = cnstringf(&buf, """+test[0]+""");
			stringf("%s(%d)", buf, ret);
			free(buf);
			return (EXIT_SUCCESS);
		}
	""")
	outfile_name = "tester/infiles/" + "stringf" + "_" \
		+ str(test_list.index(test)).zfill(3)          \
		+ "_test.out"
	with open(outfile_name, 'w') as outfile:
		outfile.write(test[1])