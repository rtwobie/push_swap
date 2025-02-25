/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/22 16:36:32 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// indexes the array by value
int	indexing(t_elem *a, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < size)
	{
		j = 0;
		x = 0;
		while (j < size)
		{
			if (a[i].num == a[j].num && i != j)
				return (1);
			if (a[i].num > a[j].num)
				x++;
			j++;
		}
		a[i].idx = x;
		i++;
	}
	return (0);
}

// rotates entry position to beginning
/*int	calc_ops(t_stack a, t_stack b, int entry_position, t_op *direction)*/
/*{*/
/*	int	pivot;*/
/*	int	operations;*/
/**/
/*	pivot = stack.size / 2;*/
/*	if ((stack.size - entry_position) >= pivot)*/
/*	{*/
/*		operations = entry_position - 1;*/
/*		*direction = ROTATE;*/
/*	}*/
/*	else if ((stack.size - entry_position) < pivot)*/
/*	{*/
/*		operations = stack.size - entry_position + 1;*/
/*		*direction = R_ROTATE;*/
/*	}*/
/*	return (operations);*/
/*}*/
#include <limits.h>
int calc_pos_b(int idx_a, t_stack b)
{
	int	pos_b;
	int lowest_high;
	int highest_low;

	pos_b = 0;
	lowest_high = INT_MAX;
	highest_low = 0;
	while (pos_b < b.size)
	{
		if (b.entry[pos_b].idx > idx_a)
		{
			if(b.entry[pos_b].idx < lowest_high)
				lowest_high = b.entry[pos_b].idx;
		}
		if (b.entry[pos_b].idx < idx_a)
		{
			if(b.entry[pos_b].idx > highest_low)
				highest_low = b.entry[pos_b].idx;
		}
		pos_b++;
	}
	ft_printf("higher: %i\t lower: %i\n", lowest_high, highest_low);
	return (pos_b);
}

void	sort(t_stack a, t_stack b)
{
	if (indexing(a.entry, a.size) == 1)
	{
		free(a.entry);
		free(b.entry);
		exit(1);
	}

}
