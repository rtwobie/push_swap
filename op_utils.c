/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:04:13 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/03 15:51:32 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	up_bound(t_elem up_bnd, int pos_b, int current_idx, int idx_a)
{
	if (current_idx > idx_a)
	{
		if (current_idx < up_bnd.idx)
		{
			up_bnd.idx = current_idx;
			up_bnd.val = pos_b;
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
			low_bnd.val = pos_b;
		}
	}
	return (low_bnd);
}

int	max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	if (nb2 > nb1)
		return (nb2);
	return (nb1);
}

int	min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	if (nb2 < nb1)
		return (nb2);
	return (nb1);
}
