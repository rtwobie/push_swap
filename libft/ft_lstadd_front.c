/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:32:24 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/06 19:15:47 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Adds a pointer in front of the new node.
 *
 * @param lst A pointer to the head of the list.
 * @param new A pointer to new created head.
 * @return none
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list *names = NULL;*/
/*	names = ft_lstnew("Robbie");*/
/*	ft_lstadd_front(&names, ft_lstnew("2B"));*/
/*	printf("%s\n", (char *)names->content);*/
/*}*/

/*
 * QUESTION:
 *		why double pointer and not single?
 */
