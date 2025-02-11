/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:17:20 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/06 19:47:27 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list *names = NULL;*/
/*	printf("\n%i\n", ft_lstsize(names));*/
/*	ft_lstadd_front(&names, ft_lstnew("A2"));*/
/*	ft_lstadd_front(&names, ft_lstnew("9S"));*/
/*	ft_lstadd_front(&names, ft_lstnew("2B"));*/
/**/
/*	t_list *temp = names;*/
/*	while (temp)*/
/*	{*/
/*		printf("%s\n", (char *)temp->content);*/
/*		temp = temp->next;*/
/*	}*/
/*	printf("\nsize: %i\n", ft_lstsize(names));*/
/*}*/
