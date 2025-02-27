/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:56:05 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/27 18:24:52 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack stack)
{
	t_elem	temp;

	temp = stack.entry[1];
	stack.entry[1] = stack.entry[0];
	stack.entry[0] = temp;
}

void	rrot(t_stack stack)
{
	t_elem	temp;

	temp = stack.entry[stack.size - 1];
	while (--stack.size > 0)
	{
		stack.entry[stack.size] = stack.entry[stack.size - 1];
	}
	stack.entry[0] = temp;
}

void	rot(t_stack stack)
{
	int		i;
	t_elem	temp;

	i = 0;
	temp = stack.entry[0];
	while (i < stack.size)
	{
		stack.entry[i] = stack.entry[i + 1];
		i++;
	}
	stack.entry[stack.size - 1] = temp;
}

void	push(t_stack *src, t_stack *dest)
{
	int	i;

	i = dest->size;
	while (i > 0)
	{
		dest->entry[i] = dest->entry[i - 1];
		i--;
	}
	dest->entry[0] = src->entry[0];
	dest->size++;
	i = 0;
	while (i < src->size)
	{
		src->entry[i] = src->entry[i + 1];
		i++;
	}
	src->size--;
}
