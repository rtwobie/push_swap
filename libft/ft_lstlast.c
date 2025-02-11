/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:32:25 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/06 19:47:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Returns the last node of the list.
 *
 * @param The beginning of the list.
 * @return Pointer to the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list *names = NULL;*/
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
/*	printf("\nlast node has: %s\n", (char *)ft_lstlast(names)->content);*/
/*}*/
