/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:56:05 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/20 21:17:10 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_elem *stack)
{
	t_elem	temp;

	temp = stack[1];
	stack[1] = stack[0];
	stack[0] = temp;
}

void	rrot(struct s_stack stack, char name)
{
	t_elem	temp;

	temp = stack.entry[stack.size - 1];
	while (--stack.size > 0)
	{
		stack.entry[stack.size] = stack.entry[stack.size - 1];
	}
	stack.entry[0] = temp;
	ft_printf("rr%c\n", name);
}

void	rot(struct s_stack stack, char name)
{
	int	i;
	t_elem	temp;

	i = 0;
	temp = stack.entry[0];
	while (i < stack.size)
	{
		stack.entry[i] = stack.entry[i + 1];
		i++;
	}
	stack.entry[stack.size - 1] = temp;
	ft_printf("r%c\n", name);
}

void	push(struct s_stack *src, struct s_stack *dest)
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
