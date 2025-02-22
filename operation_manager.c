/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:17:06 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/22 16:59:37 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap_manager(t_stack stack1, t_stack stack2, t_op type)
{
	if (type == SWAP)
	{
		swap(stack1);
		ft_printf("s%c\n", stack1.name);
	}
	if (type == SWAP2)
	{
		swap(stack1);
		swap(stack2);
		ft_printf("ss\n");
	}
}

void	rot_manager(t_stack stack1, t_stack stack2, t_op type)
{
	if (type == ROTATE)
	{
		rot(stack1);
		ft_printf("r%c\n", stack1.name);
	}
	if (type == ROTATE2)
	{
		rot(stack1);
		rot(stack2);
		ft_printf("rr\n");
	}
	if (type == R_ROTATE)
	{
		rrot(stack1);
		ft_printf("rr%c\n", stack1.name);
	}
	if (type == R_ROTATE2)
	{
		rrot(stack1);
		rrot(stack2);
		ft_printf("rrr\n");
	}
}

void	op_manager(t_op type, int amount, t_stack *src, t_stack *dest)
{
	while (amount > 0)
	{
		if (type == SWAP)
			swap_manager(*src, *dest, SWAP);
		if (type == SWAP2)
			swap_manager(*src, *dest, SWAP2);
		if (type == ROTATE)
			rot_manager(*src, *dest, ROTATE);
		if (type == ROTATE2)
			rot_manager(*src, *dest, ROTATE2);
		if (type == R_ROTATE)
			rot_manager(*src, *dest, R_ROTATE);
		if (type == R_ROTATE2)
			rot_manager(*src, *dest, R_ROTATE2);
		if (type == PUSH)
		{
			push(src, dest);
			ft_printf("p%c\n", dest->name);
		}
		amount--;
	}
}
