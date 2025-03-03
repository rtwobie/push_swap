/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/28 20:29:40 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// indexes the array by value
int	indexing(t_stack *a)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < a->size)
	{
		j = 0;
		x = 0;
		while (j < a->size)
		{
			if (a->entry[i].val == a->entry[i].val && i != j)
				return (1);
			if (a->entry[i].val > a->entry[j].val)
				x++;
			j++;
		}
		a->entry[i].idx = x;
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if (a->entry[i].idx != i)
			return (0);
		i++;
	}
	return (1);
}

void sort_three(t_stack *a)
{

}

int	sort(t_stack *a, t_stack *b)
{
	int	i;

	if (indexing(a) != 0)
		return (1);
	if (is_sorted(a))
		return (1);
	i = a->size;
	while (i > 3)
	{
		move_manager(a, b);
		op_manager(PUSH, 1, a, b);
		i--;
	}
	sort_three();
	return (0);
}
