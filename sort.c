/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 02:15:48 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_arr(t_stack *a, t_stack *b, int length);

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
	int	size;

	if (b->size == 0)
		return ;
	rot_to_top(b, find_biggest(b));
	size = b->size;
	while (size > 0)
	{
		if (a->entry[a->size - 1].idx > b->entry[0].idx)
			op_manager(R_ROTATE, 1, a, b);
		op_manager(PUSH, 1, b, a);
		size--;
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
		return (2);
	}
	if (a->size == 4)
		op_manager(PUSH, 1, a, b);
	else if (a->size >= 5)
		op_manager(PUSH, 2, a, b);
	i = a->size;
	while (i > 3)
	{
		move_manager(a, b);
		op_manager(PUSH, 1, a, b);
		i--;
	}
	sort_three(a);
	push_back(a, b);
	rot_to_top(a, find_smallest(a));
	return (0);
}
