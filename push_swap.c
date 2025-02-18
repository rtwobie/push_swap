/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:56:05 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/17 16:13:14 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	swap(int *stack)
{
	int	temp;

	temp = stack[1];
	stack[1] = stack[0];
	stack[0] = temp;
}

void	rrot(int *stack, int length)
{
	int	temp;

	temp = stack[length - 1];
	while (--length > 0)
	{
		stack[length] = stack[length - 1];
	}
	stack[0] = temp;
}

void	rot(int *stack, int length)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[0];
	while (i < length)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[length - 1] = temp;
}

void	push(int src, int *dest, int length)
{
	dest = realloc(dest, sizeof(int) * (++length));
	if (!dest)
		return ;
	rrot(dest, length);
	dest[0] = src;
}

