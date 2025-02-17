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

void	swap(int **stack)
{
	int	temp;

	temp = *stack[1];
	*stack[1] = *stack[0];
	*stack[0] = temp;
}

void	push(int *src, int *dest, int length)
{
	ft_realloc(dest, sizeof(int) * (length + 1));
	if (!dest)
		return ;
	while (length)
	{
		dest[length + 1] = dest[length];
		length--;
	}
	dest[0] = src[0];
}
