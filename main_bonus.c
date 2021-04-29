#include <stdio.h>
#include <stdlib.h>
#include "./libasm_bonus.h"
#include <unistd.h>
#include <string.h>

void	ft_hello(void *a, void *b)
{
	printf("a = %s, b = %s\n", *(char **)a, *(char **)b);
}

void	ft_list_size_tests(int till)
{
	int x;
	int y;
	int i;
	t_list *head;
	t_list *temp;
	char *test;
	char *test1;
	int copy;
	
	i = 0;	
	if (till == 0)
	{
		x = ft_lstsize(NULL);
		y = ft_list_size(NULL);
		if (x == y)
			printf("WINNER!\n");
		return ;
	}
	copy = 0;
	i = 0;
	test = strdup("Hello");
	test1 = strdup("Goodbye");
	head = NULL;
	while (i < till)
	{
		if (i % 2 == 0)	
			ft_list_push_front(&head, test);
		else
			ft_list_push_front(&head, test1);
		i++;

	}
	x = ft_lstsize(head);
	y = ft_list_size(head);
	ft_lstprinter(head);
	printf("Libft lst_size result: %i\n", x);
	printf("Libasm list_size result: %i\n", y);
	if (x == y)
	{
		printf("FT_LIST_SIZE QUEST: SUCCESS!\n");
		printf("FT_LIST_PUSH_FRONT QUEST: SUCCESS!\n");
	}
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
	free(test);
	free(test1);
}

int main(void)
{
	ft_list_size_tests(5);
	ft_list_size_tests(0);
	ft_list_size_tests(20);
	return (0);
}
