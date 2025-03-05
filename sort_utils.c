/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:05:02 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 02:10:35 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < stack->size)
	{
		if (stack->entry[i].idx < stack->entry[pos].idx)
			pos = i;
		i++;
	}
	return (pos);
}

int	find_biggest(t_stack *stack)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < stack->size)
	{
		if (stack->entry[i].idx > stack->entry[pos].idx)
			pos = i;
		i++;
	}
	return (pos);
}

void rot_to_top(t_stack *stack, int pos)
{
	if (pos > 0)
	{
		if (pos <= (stack->size / 2))
			operation(ROTATE, pos, stack);
		if (pos > (stack->size / 2))
			operation(R_ROTATE, (stack->size - pos), stack);
	}
}

