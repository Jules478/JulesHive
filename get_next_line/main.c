#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define RED    "\e[1;31m"
#define GREEN   "\e[1;32m"
#define BOLD    "\e[1;35m"
#define RESET   "\x1b[0m"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((s1a[i] == s2a[i]) && (s1a[i] || s2a[i]) && i < n - 1)
	{
		if (s1a[i] == s2a[i])
			i++;
		else
			return (s1a[i] - s2a[i]);
	}
	return (s1a[i] - s2a[i]);
}

void	texttest(fd)
{
	int		i;
	char	*line;
	
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("Line %d: %s\n", i + 1, line);
		i++;
		if (i == 5 && line == NULL)
		{
			printf(RED);
			printf("File not completely Read\n\n");
			printf(RESET);
		}
		else if (i == 5)
		{
			printf(GREEN);
			printf("File Completely Read\n\n");
			printf(RESET);
		}
		free(line);
	}
}

void	smallfiletest(fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("Line %d: %s\n", i + 1, line);
		i++;
		if (i == 3 && line == NULL)
		{
			printf(RED);
			printf("File not completely Read\n\n");
			printf(RESET);
		}
		else if (i == 3)
		{
			printf(GREEN);
			printf("File Completely Read\n\n");
			printf(RESET);
		}
		free(line);
	}
}

void	wiki(fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 505)
	{
		line = get_next_line(fd);
		printf("Line %d: %s\n", i + 1, line);
		i++;
		if (i == 505 && line == NULL)
		{
			printf(RED);
			printf("File not completely Read\n\n");
			printf(RESET);
		}
		else if (i == 505)
		{
			printf(GREEN);
			printf("File Completely Read\n\n");
			printf(RESET);
		}
		free(line);
	}
}

void	nltest(fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("Line %d: %s\n", i + 1, line);
		i++;
		if (i == 15 && line == NULL)
		{
			printf(RED);
			printf("File not completely Read\n\n");
			printf(RESET);
		}
		else if (i == 15)
		{
			printf(GREEN);
			printf("File Completely Read\n\n");
			printf(RESET);
		}
		free(line);
	}
}

void	invalidfd(fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	printf("Line %d: %s\n", i + 1, line);
	if (line != NULL)
	{
		printf(RED);
		printf("fd is valid\n");
		printf(RESET);
	}
	else
	{
		printf(GREEN);
		printf("fd is invalid\n\n");
		printf(RESET);
	}
	free(line);
}

void	terminaltest(void)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(0);
	printf("\nTerminal: %s\n", line);
	if (line == NULL)
	{
		printf(RED);
		printf("Standard Input Not Read\n\n");
		printf(RESET);
	}
	else
	{
		printf(GREEN);
		printf("Standard Input Read\n\n");
		printf(RESET);
	}
	free(line);
}

int main()
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	test_choice[100];

	while(1)
	{
		printf(BOLD);
		printf("\nCommands:\n");
		printf(RESET);
		printf("txttest\nsmalltest\nwikitest\nonlynl\nempty\nstdinput\ninvalid\nall\nbonus\nexit\n");
		printf("\nEnter Command: ");
		fgets(test_choice, sizeof(test_choice), stdin);
		test_choice[strcspn(test_choice, "\n")] = 0;
		printf("\n");
		if (!ft_strncmp(test_choice, "txttest", 8))
		{
			fd = open("readthis.txt", O_RDONLY);
			texttest(fd);
			close(fd);
		}
		else if (!ft_strncmp(test_choice, "smalltest", 10))
		{
			fd = open("readthis2.txt", O_RDONLY);
			smallfiletest(fd);
			close(fd);
		}
		else if (!ft_strncmp(test_choice, "wikitest", 9))
		{
			fd = open("readthis4.txt", O_RDONLY);
			wiki(fd),
			close(fd);
		}
		else if (!ft_strncmp(test_choice, "onlynl", 7))
		{
			fd = open("cantreadthis2.txt", O_RDONLY);
			nltest(fd);
			close(fd);
		}
		else if (!ft_strncmp(test_choice, "invalid", 6))
		{
			invalidfd(999);
		}
		else if (!ft_strncmp(test_choice, "stdinput", 9))
		{
			terminaltest();
		}
		else if (!ft_strncmp(test_choice, "all", 4))
		{
			fd = open("readthis.txt", O_RDONLY);
			texttest(fd);
			close(fd);
			fd = open("readthis2.txt", O_RDONLY);
			smallfiletest(fd);
			close(fd);
			fd = open("readthis4.txt", O_RDONLY);
			wiki(fd),
			close(fd);
			fd = open("cantreadthis2.txt", O_RDONLY);
			nltest(fd);
			close(fd);
			invalidfd(999);
			printf(BOLD);
			printf("Enter text to print: \n");
			printf(RESET);
			terminaltest();
		}
		else if (!ft_strncmp(test_choice, "bonus", 6))
		{
			fd = open("readthis.txt", O_RDONLY);
			fd2 = open("readthis2.txt", O_RDONLY);
			fd3 = open("readthis4.txt", O_RDONLY);
			line = get_next_line(fd);
			printf(BOLD);
			printf("S1L1:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd2);
			printf(BOLD);
			printf("S2L1:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd3);
			printf(BOLD);
			printf("S3L1:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd);
			printf(BOLD);
			printf("S1L2:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd2);
			printf(BOLD);
			printf("S2L2:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd3);
			printf(BOLD);
			printf("S3L2:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd);
			printf(BOLD);
			printf("S1L3:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd2);
			printf(BOLD);
			printf("S2L3:\n");
			printf(RESET);
			printf("%s\n", line);
			line = get_next_line(fd3);
			printf(BOLD);
			printf("S3L3:\n");
			printf(RESET);
			printf("%s\n", line);
			close(fd);
			close(fd2);
			close(fd3);
		}
		else if (!ft_strncmp(test_choice, "exit", 5))
			return (0);
	}
}
