/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:06:30 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/27 20:02:32 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

t_elem	up_bound(t_elem up_bnd, int pos_b, int current_idx, int idx_a)
{
	if (current_idx > idx_a)
	{
		if (current_idx < up_bnd.idx)
		{
			up_bnd.idx = current_idx;
			up_bnd.num = pos_b;
		}
	}
	return (up_bnd);
}

t_elem	low_bound(t_elem low_bnd, int pos_b, int current_idx, int idx_a)
{
	if (current_idx < idx_a)
	{
		if (current_idx > low_bnd.idx)
		{
			low_bnd.idx = current_idx;
			low_bnd.num = pos_b;
		}
	}
	return (low_bnd);
}

int	calc_pos_b(int idx_a, t_stack b)
{
	int		pos_b;
	t_elem	up_bnd;
	t_elem	low_bnd;

	pos_b = 0;
	up_bnd.idx = INT_MAX;
	low_bnd.idx = 0;
	while (pos_b < b.size)
	{
		up_bnd = up_bound(up_bnd, pos_b, b.entry[pos_b].idx, idx_a);
		low_bnd = low_bound(low_bnd, pos_b, b.entry[pos_b].idx, idx_a);
		pos_b++;
	}
	if (up_bnd.idx == INT_MAX)
	{
		up_bnd.idx = idx_a;
		up_bnd.num = low_bnd.num - 1;
	}
	if (low_bnd.idx == 0 && up_bnd.num == b.size - 1)
		low_bnd.num = 0;
	else if (low_bnd.idx == 0)
		low_bnd.num = up_bnd.num + 1;
	ft_printf("\na index = %i\n", idx_a);
	ft_printf("High Pos: %i\t High Index: %i\n", up_bnd.num, up_bnd.idx);
	ft_printf("Low Pos: %i\t Low Index: %i\n", low_bnd.num, low_bnd.idx);
	return (low_bnd.num);
}
