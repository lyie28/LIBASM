/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:44:56 by lyie              #+#    #+#             */
/*   Updated: 2021/04/28 17:18:16 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstprinter(t_list *lst)
{
	while (lst)
	{
		printf("data is: %s\n", (char *)(lst->data));
		lst = lst->next;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	while (*alst)
	{
		if ((*alst)->next == NULL)
		{
			(*alst)->next = new;
			*alst = tmp;
			return ;
		}
		*alst = (*alst)->next;
	}
	*alst = new;
	return ;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(void *data)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

int	ft_lstsize(t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
