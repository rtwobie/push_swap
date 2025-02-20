/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:04 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/20 21:17:05 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
		a[i].index = x;
		i++;
	}
	return (0);
}

void	sort(struct s_stack a, struct s_stack b)
{
	// indexing
	// terminate at duplicates
	if (indexing(a.entry, a.size) == 1)
	{
		free(a.entry);
		free(b.entry);
		exit(1);
	}
}
