/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:37:19 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "operations.h"
#include "sort.h"
#include "move.h"

// checks also for duplicates
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

void	rot_to_top(t_stack *stack, int pos)
{
	if (pos > 0)
	{
		if (pos <= (stack->size / 2))
			operation(ROTATE, pos, stack);
		if (pos > (stack->size / 2))
			operation(R_ROTATE, (stack->size - pos), stack);
	}
}

void	sort_three(t_stack *a)
{
	if (a->size != 3)
		return ;
	while (1)
	{
		if (a->entry[0].idx < a->entry[1].idx && \
			a->entry[1].idx < a->entry[2].idx)
			return ;
		else if (a->entry[2].idx < a->entry[0].idx && \
				a->entry[0].idx < a->entry[1].idx)
			operation(R_ROTATE, 1, a);
		else if (a->entry[1].idx < a->entry[2].idx && \
				a->entry[2].idx < a->entry[0].idx)
			operation(ROTATE, 1, a);
		else
			operation(SWAP, 1, a);
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	limit;

	limit = 3;
	if (b->size == 0)
		return ;
	rot_to_top(b, find_biggest(b));
	while (b->size > 0)
	{
		if (a->entry[a->size - 1].idx > b->entry[0].idx && limit > 0)
		{
			operation(R_ROTATE, 1, a);
			limit--;
		}
		else
			operation2(PUSH, 1, b, a);
	}
}

int	sort(t_stack *a, t_stack *b)
{
	int	i;

	if (indexing(a) != 0)
		return (1);
	if (is_sorted(a) || a->size < 3)
	{
		rot_to_top(a, find_smallest(a));
		return (0);
	}
	if (a->size == 4)
		operation2(PUSH, 1, a, b);
	else if (a->size >= 5)
		operation2(PUSH, 2, a, b);
	i = a->size;
	while (i > 3)
	{
		move_manager(a, b);
		operation2(PUSH, 1, a, b);
		i--;
	}
	sort_three(a);
	push_back(a, b);
	rot_to_top(a, find_smallest(a));
	return (0);
}
