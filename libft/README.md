# libft

## What is it?

Libft (Library Forty-Two) is the first project in the 42 network of coding schools.
It is a library consisting of custom implementations of various library functions along with a few custom functions.
These functions are then used throughout other projects at the school. 

## What Functions?

Many. Here is a list of the functions, where they're from, and a brief overview of their purposes.

### Functions from `<ctype.h>`

- [`ft_isalpha`](ft_isalpha.c)	- checks if a passed character is alphabetical.
- [`ft_isdigit`](ft_isdigit.c)	- checks if a passed character is numerical (0 - 9).
- [`ft_isalnum`](ft_isalnum.c)	- checks if a passed character is alphanumerical.
- [`ft_isascii`](ft_isascii.c)	- checks if a passed character is in the ASCII set.
- [`ft_isprint`](ft_isprint.c)	- checks if a passed character is printable.
- [`ft_toupper`](ft_toupper.c)	- converts a lowercase character to uppercase.
- [`ft_tolower`](ft_tolower.c)	- converts an uppercase character to lowercase.

### Functions from `<string.h>`

- [`ft_memset`](ft_memset.c)	- set a memory area to a specified character.
- [`ft_strlen`](ft_strlen.c)	- calculate the length of a string.
- [`ft_bzero`](ft_bzero.c)	    - set a memory area to null values.
- [`ft_memcpy`](ft_memcpy.c)	- copy memory (cannot overlap).
- [`ft_memmove`](ft_memmove.c)	- copy memory (checks for overlap).
- [`ft_strlcpy`](ft_strlcpy.c)	- copy a specified number of bytes of a string.
- [`ft_strlcat`](ft_strlcat.c)	- concatenates a specified number of bytes onto another string.
- [`ft_strchr`](ft_strchr.c)	- locate first instance of specified character in a string.
- [`ft_strrchr`](ft_strrchr.c)	- locate last instance of a specified character in a string.
- [`ft_strncmp`](ft_strncmp.c)	- compares two strings.
- [`ft_memchr`](ft_memchr.c)	- locate first instance of a specified character in a memory area.
- [`ft_memcmp`](ft_memcmp.c)	- compare two memory areas.
- [`ft_strnstr`](ft_strnstr.c)	- locate a specified substring within a second string.
- [`ft_strdup`](ft_strdup.c)	- allocate a new string and copies the contents of another string into it.

### Functions from `<stdlib.h>`
- [`ft_atoi`](ft_atoi.c)	    - convert a string to an integer.
- [`ft_calloc`](ft_calloc.c)	- allocate memory and sets the contents to null values.

### Non-standard functions
- [`ft_substr`](ft_substr.c)	     - locate and return a specified string within a second string.
- [`ft_strjoin`](ft_strjoin.c)	     - concatenate two strings.
- [`ft_strtrim`](ft_strtrim.c)	     - remove specified characters from the start and end of a string.
- [`ft_split`](ft_split.c)	         - split a string into an array deliminated by a specified character.
- [`ft_itoa`](ft_itoa.c)	         - convert an integer into a string.
- [`ft_strmapi`](ft_strmapi.c)  	 - create a new string apply a specified function to each character of a string.
- [`ft_striteri`](ft_striteri.c)	 - apply a specified function to each character of a string.
- [`ft_putchar_fd`](ft_putchar_fd.c) - write a single character to a specified location.
- [`ft_putstr_fd`](ft_putstr_fd.c)   - write a string to a specified location.
- [`ft_putendl_fd`](ft_putendl_fd.c) - write a string to a specified location followed by a new line.
- [`ft_putnbr_fd`](ft_putnbr_fd.c)	 - write an integer to a specified location.

### Linked list functions

- [`ft_lstnew`](ft_lstnew.c)	            - create a new list element.
- [`ft_lstadd_front`](ft_lstadd_front.c)	- add an element at the beginning of a list.
- [`ft_lstsize`](ft_lstsize.c)	            - count the number of elements in a list.
- [`ft_lstlast`](ft_lstlast.c)	            - return the last element of the list.
- [`ft_lstadd_back`](ft_lstadd_back.c)	    - add an element at the end of a list.
- [`ft_lstclear`](ft_lstclear.c)	        - delete and free list.
- [`ft_lstiter`](ft_lstiter.c)	            - apply a function to each element of a list.
- [`ft_lstmap`](ft_lstmap.c)	            - create a new list apply a function to each element of a list.

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.