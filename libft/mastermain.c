#include <stdio.h>
#include <string.h>
#include "libft.h"

char	testfunc1(unsigned int i, char c)
{
	printf("Index %d of str is: %c\n", i, c);
	return (0);
}

void	testfunc2(unsigned int i, char *c)
{
	if (ft_isalpha(*c) == 1)
		*c = ft_toupper((int)*c);
	printf("Index %d is %c\n", i, *c);
}

int	main()
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;
	char	test1;
	char	test2;
	char	test3;
	char	test4;
	char	delimit;
	char	memtest1[] = "12345";
	char	memtest2[99];
	char	memtest3[] = "12345";
	char	memtest4[99];
	char	memtest5[99];
	char	iteri[6] = "123ab";
	int	i;
	int	memtestcount;
	int	*callocptr;
	int	itoa1;
	int	itoa2;

	str1 = "12345";
	str2 = "-12345";
	str3 = "--123";
	str4 = "123ab";
	str5 = "";
	str6 = "23";
	str7 = "15";
	str8 = " This                           code was really hard";
	test1 = 'a';
	test2 = '1';
	test3 = '-';
	test4 = 0;
	delimit = 32;
	itoa1 = 12345;
	itoa2 = -12345;

	printf("atoi: %d\n", ft_atoi(str1));
	printf("atoi: %d\n", ft_atoi(str2));
	printf("atoi: %d\n", ft_atoi(str3));
	printf("atoi: %d\n\n", ft_atoi(str4));

	printf("is a alnum: %d\n", ft_isalnum(test1));
	printf("is 1 alnum: %d\n", ft_isalnum(test2));
	printf("is - alnum: %d\n\n", ft_isalnum(test3));

	printf("is a alpha: %d\n", ft_isalpha(test1));
	printf("is 1 alpha: %d\n", ft_isalpha(test2));
	printf("is - alpha: %d\n\n", ft_isalpha(test3));

	printf("is a ascii: %d\n", ft_isascii(test1));
	printf("is 1 ascii: %d\n", ft_isascii(test2));
	printf("is - ascii: %d\n\n", ft_isascii(test3));

	printf("is a digit: %d\n", ft_isdigit(test1));
	printf("is 1 digit: %d\n", ft_isdigit(test2));
	printf("is - digit: %d\n\n", ft_isdigit(test3));

	printf("is a print: %d\n", ft_isprint(test1));
	printf("is null print: %d\n\n", ft_isprint(test4));

	printf("memchr: %p\n", ft_memchr(str1, '3', 5));
	printf("memchr: %p\n\n", ft_memchr(str5, '1', 5));

	printf("memcmp: %d\n", ft_memcmp(str1, str2, 5));
	printf("memcmp: %d\n", ft_memcmp(str2, str1, 1));
	printf("memcmp real: %d\n", memcmp(str1, str2, 5));
	printf("memcmp real: %d\n\n", memcmp(str2, str1, 1));

	printf("memcpy: %p\n\n", ft_memcpy(memtest2, memtest1, 5));

	printf("memmove: %p\n\n", ft_memmove(memtest4, memtest3, 5));

	ft_memset(memtest5, '1', 10);
	i = 0;
	memtestcount = 0;
	while (i < 10)
	{
		if (memtest5[i] == '1')
			memtestcount++;
		i++;
	}
	if (memtestcount == 10)
		printf("memset successful\n\n");
	else
		printf("memset failed\n\n");

	ft_bzero(memtest5, 10);
	i = 0;
	memtestcount = 0;
	while (i < 10)
	{
		if (memtest5[i] == '\0')
			memtestcount++;
		i++;
	}
	if (memtestcount == 10)
		printf("bzero successful\n\n");
	else
		printf("bzero failed\n\n");

	printf("strchr: %p\n", ft_strchr(str1, '2'));
	printf("strchr: %p\n\n", ft_strchr(str1, 'a'));

	printf("strlen: %zu\n\n", ft_strlen(str1));

	printf("strdup: %s\n", ft_strdup(str1));
	printf("strdup: %s\n\n", ft_strdup(str5));

	printf("strlcat n = 5: %zu\n", ft_strlcat(memtest2, memtest1, 5));
	printf("strlcat n = 3: %zu\n\n", ft_strlcat(memtest2, memtest1, 3));

	printf("strlcpy n = 5: %zu\n", ft_strlcpy(memtest2, memtest1, 5));
	printf("strlcpy n = 3: %zu\n\n", ft_strlcpy(memtest2, memtest1, 3));

	printf("strncmp n = 5: %d\n", ft_strncmp(str1, str4, 5));
	printf("strncmp n = 3: %d\n\n", ft_strncmp(str1, str4, 3));

	printf("strnstr n = 5: %s\n", ft_strnstr(str1, str6, 5));
	printf("strnstr n = 3: %s\n\n", ft_strnstr(str1, str6, 3));

	printf("strrchr c = 3: %p\n", ft_strrchr(str1, '3'));
	printf("strrchr c = a: %p\n\n", ft_strrchr(str1, 'a'));

	printf("tolower c = A: %c\n", ft_tolower('A'));
	printf("tolower c = 5: %c\n\n", ft_tolower('5'));
	
	printf("topupper c = a: %c\n", ft_toupper('a'));
	printf("toupper c = 5: %c\n\n", ft_toupper('5'));

	callocptr = ft_calloc(10, 4);
	if ((char *)callocptr == NULL)
	{
		printf("calloc nulled\n");

	}
	i = 0;
	memtestcount = 0;
	while (i < 10)
	{
		if (callocptr[i] == 0)
			memtestcount++;
		i++;
	}
	if (memtestcount == 10)
		printf("calloc successful\n\n");
	else
		printf("calloc failed\n\n");
	free(callocptr);

	printf("substr original: %s\n", str1);
	printf("substr sub: %s\n\n", ft_substr(str1, 1, 3));

	printf("strjoin: %s\n\n", ft_strjoin(str1, str2));

	printf("strtrim s1: %s\n", str1);
	printf("strtrim set: %s\n", str7);
	printf("strtrim result: %s\n\n", ft_strtrim(str1, str7));

	printf("split: ");
	i = 0;
	while (i < 5)
	{
		printf("%s / ", ft_split(str8, delimit)[i]);
		i++;
	}
	printf("\n\n");

	printf("itoa: %s\n", ft_itoa(itoa1));
	printf("itoa: %s\n\n", ft_itoa(itoa2));

	printf("strmapi: %s\n", str4);
	ft_strmapi(str4, testfunc1);
	printf("\n");

	printf("striteri: %s\n", iteri);
	ft_striteri(iteri, testfunc2);
	printf("\n");

	printf("putchar_fd:\n");
	ft_putchar_fd(test1, 1);
	printf("\n\n");

	printf("putstr_fd:\n");
	ft_putstr_fd(str1, 1);
	printf("\n\n");

	printf("putendl_fd:\n");
	ft_putendl_fd(str1, 1);
	printf("New line above\n\n");

	printf("putnbr_fd:\n");
	ft_putnbr_fd(itoa1, 1);
	printf("\n");
	ft_putnbr_fd(itoa2, 1);
	printf("\n\n");

	return (0);
}
