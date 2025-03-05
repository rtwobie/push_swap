/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:05:02 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:31:28 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

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

int	is_sorted(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < a->size && a->entry[j].idx != 0)
		j++;
	while (i < a->size)
	{
		if (j == a->size)
			j = 0;
		if (a->entry[j].idx != i)
			return (0);
		i++;
		j++;
	}
	return (1);
}
