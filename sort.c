/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/04 21:15:49 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// index array by value and fails at duplicates
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
			if (a->entry[i].val == a->entry[j].val && i != j)
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

void	sort_three(t_stack *a)
{
	while (1)
	{
		if (a->entry[0].idx < a->entry[1].idx && \
			a->entry[1].idx < a->entry[2].idx)
			return ;
		else if (a->entry[2].idx < a->entry[0].idx && \
				a->entry[0].idx < a->entry[1].idx)
			operation(a, R_ROTATE);
		else if (a->entry[1].idx < a->entry[2].idx && \
				a->entry[2].idx < a->entry[0].idx)
			operation(a, ROTATE);
		else
			operation(a, SWAP);
	}
}

/*void push_back(t_stack *a, t_stack *b)*/
/*{*/
/*}*/

int	sort(t_stack *a, t_stack *b)
{
	int	i;

	if (indexing(a) != 0)
		return (1);
	if (!is_sorted(a))
		return (2);
	i = a->size;
	while (i > 3)
	{
		move_manager(a, b);
		op_manager(PUSH, 1, a, b);
		i--;
	}
	sort_three(a);
	return (0);
}
