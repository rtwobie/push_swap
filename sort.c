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
			if (a[i].val == a[j].val && i != j)
				return (1);
			if (a[i].val > a[j].val)
				x++;
			j++;
		}
		a[i].idx = x;
		i++;
	}
	return (0);
}

void	sort(t_stack *a, t_stack *b)
{
	if (indexing(a->entry, a->size) == 1)
	{
		free(a->entry);
		free(b->entry);
		exit(1);
	}

}
