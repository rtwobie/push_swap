/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:21:34 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/06 19:39:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 *	@brief Create a new node.
 *
 *	Allocates (with malloc(3)) and returns a new node.
 *	The member variable ’content’ is initialized with
 *	the value of the parameter ’content’. The variable
 *	’next’ is initialized to NULL.
 *
 *	@param content The value to be initialized when the list gets created.
 *	@return A pointer to the list.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list *names;*/
/**/
/*	names = ft_lstnew("Robbie");*/
/*	printf("%s\n", (char *)names->content);*/
/*}*/
