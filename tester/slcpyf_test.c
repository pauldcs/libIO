#include "libstringf.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *src1;
	char dst1[10];
	int ret1;

	char *src2;
	char dst2[10];
	int ret2;

	src1 = "coucou";
	src2 = "coucou";

	printf ("test 1:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1 + 1, src1, 0);
	ret2 = slcpyf(dst2 + 1, 0, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %c : %c\n", *dst1, *dst2);
	
	printf ("test 2:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1, src1, 1);
	ret2 = slcpyf(dst2, 1, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %x %c : %x %c\n", dst1[0], dst1[1], dst2[0], dst2[1]);

	printf ("test 3:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1, src1, 2);
	ret2 = slcpyf(dst2, 2, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %c %x %c: %c %x %c\n", dst1[0], dst1[1], dst1[2], dst2[0], dst2[1], dst2[2]);

	printf ("test 4:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1, src1, 6);
	ret2 = slcpyf(dst2, 6, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %d : %d\n", memcmp(src1, dst1, 5), memcmp(src2, dst2, 5));
	printf (" - %x %c : %x %c\n", dst1[5], dst1[1], dst2[5], dst2[1]);

	printf ("test 5:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1, src1, 7);
	ret2 = slcpyf(dst2, 7, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %d : %d\n", memcmp(src1, dst1, 7), memcmp(src2, dst2, 7));

	printf ("test 6:\n");
	memset(dst1, 'A', 10);
	memset(dst2, 'A', 10);
	ret1 = strlcpy(dst1, src1, 8);
	ret2 = slcpyf(dst2, 8, src2);
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %d : %d\n", memcmp(src1, dst1, 7), memcmp(src2, dst2, 7));

	printf ("test 7:\n");
	memset(dst1, 0, 10);
	memset(dst2, 0, 10);
	ret1 = strlcpy(dst1, "1", 0);
	ret2 = slcpyf(dst2, 0, "1");
	printf (" - %d : %d\n", ret1, ret2);
	printf (" - %x : %x\n", *dst1, *dst2);
	return (0);
}
