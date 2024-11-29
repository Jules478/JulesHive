#include "libft.h"
#include <stdio.h>

static void	upper(void *s)
{
	int	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
}

static void	*big_upper(void *s)
{
	char	*str;

	str = ft_strdup((char *)s);
	upper(str);
	return (str);
}

void	del(void *s)
{
	free(s);
}

int	main()
{
	t_list	*list;
	char	str1[] = "Coding ";
	char	str2[] = "is ";
	char	str3[] = "really ";
	char	str4[] = "hard!";

	list = ft_lstnew(str2);
	ft_lstadd_front(&list, ft_lstnew(str1));
	ft_lstadd_back(&list, ft_lstnew(str3));
	ft_lstadd_back(&list, ft_lstnew(str4));
	printf("Full List: ");
	t_list	*temp1 = list;
	t_list	*temp2 = list;
	t_list	*temp3 = list;
	t_list	*temp4 = list;
	t_list	*temp5 = NULL;
	t_list	*temp6 = NULL;
	while (list)
	{
		printf("%s", (char *)list->content);
		list = list->next;
	}
	temp1 = ft_lstlast(temp1);
	printf("\nlstlast: %s\n", (char *)(temp1->content));
	printf("lstsize: %d\n", ft_lstsize(temp2));
	int i = 0;
	while (i < 2)
	{
		temp3 = temp3->next;
		i++;
	}
	ft_lstiter(temp3, upper);
	printf("lstiteri: Coding is ");
	printf("%s", (char *)temp3->content);
	printf("hard!\n");

	temp5 = ft_lstmap(temp4, big_upper, del);
	temp6 = temp5;
	printf("lstmap: ");
	while (temp5)
	{
		printf("%s", (char *)temp5->content);
		temp5 = temp5->next;
	}
	temp5 = ft_lstlast(temp5);
	ft_lstdelone(temp5, del);
	if (!temp5)
		printf("\nlstdelone successful\n");
	else
		printf("\nlstdelone failure\n");
	ft_lstclear(&temp6, del);
	if (!temp6)
		printf("lstclear successful\n");
	else
		printf("lstclear failure\n");
	return (0);
}
