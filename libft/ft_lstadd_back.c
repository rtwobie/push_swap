/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:47:53 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 15:24:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds the node ’new’ at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list	*names_empty = NULL;*/
/**/
/*	ft_lstadd_back(&names_empty, ft_lstnew("Robbie"));*/
/*	printf("test on empty: %s\n", (char *)ft_lstlast(names_empty)->content);*/
/**/
/*	t_list *names = NULL;*/
/*	ft_lstadd_front(&names, ft_lstnew("A2"));*/
/*	ft_lstadd_front(&names, ft_lstnew("9S"));*/
/*	ft_lstadd_front(&names, ft_lstnew("2B"));*/
/*	ft_lstadd_back(&names, ft_lstnew("Robbie"));*/
/*	t_list *temp = names;*/
/*	while (temp)*/
/*	{*/
/*		printf("%s\n", (char *)temp->content);*/
/*		temp = temp->next;*/
/*	}*/
/*}*/
