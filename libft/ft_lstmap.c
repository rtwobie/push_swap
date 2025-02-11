/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:27:54 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 17:28:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list resulting from applying a function to each element.
 *
 * Iterates through the list ’lst’ and applies the function ’f’
 * to the content of each node. A new list is created containing
 * the results of the successive applications of the function ’f’.
 * The ’del’ function is used to delete the content of a node if
 * allocation or other operations fail.
 *
 * @param lst A pointer to the first node of the list.
 * @param f The function to apply to each node's content.
 * @param del The function to delete a node's content, if needed.
 * @return A pointer to the new list, or NULL if memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = (f(lst->content));
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*static void	*rot1(void *content)*/
/*{*/
/*	char	*src;*/
/*	char	*new_str;*/
/*	int		i;*/
/**/
/*	src = (char *)content;*/
/*	new_str = ft_strdup(src);*/
/*	if(!new_str)*/
/*		return (NULL);*/
/*	i = 0;*/
/*	while (new_str[i])*/
/*	{*/
/*		new_str[i] += 1;*/
/*		i++;*/
/*	}*/
/*	return (new_str);*/
/*}*/

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	t_list *alpha = NULL;*/
/*	ft_lstadd_back(&alpha, ft_lstnew("abc"));*/
/*	ft_lstadd_back(&alpha, ft_lstnew("def"));*/
/*	ft_lstadd_back(&alpha, ft_lstnew("ghi"));*/
/*	ft_lstadd_back(&alpha, ft_lstnew("jkl"));*/
/**/
/*	t_list *temp = alpha;*/
/*	printf("Source List:\n");*/
/*	while (temp)*/
/*	{*/
/*		printf("%s\n", (char *)temp->content);*/
/*		temp = temp->next;*/
/*	}*/
/**/
/*	t_list *alpha_rot1;*/
/*	alpha_rot1 = ft_lstmap(alpha, rot1, free);*/
/*	temp = alpha_rot1;*/
/*	printf("\nMapped List:\n");*/
/*	while (temp)*/
/*	{*/
/*		printf("%s\n", (char *)temp->content);*/
/*		temp = temp->next;*/
/*	}*/
/*}*/
