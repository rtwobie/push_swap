/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:17:06 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:04:12 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"

void	operation(t_op type, int amount, t_stack *stack)
{
	while (amount > 0)
	{
		if (type == SWAP)
		{
			swap(stack);
			ft_printf("s%c\n", stack->name);
		}
		if (type == ROTATE)
		{
			rot(stack);
			ft_printf("r%c\n", stack->name);
		}
		if (type == R_ROTATE)
		{
			rrot(stack);
			ft_printf("rr%c\n", stack->name);
		}
		amount--;
	}
}

void	operation2(t_op type, int amount, t_stack *stack1, t_stack *stack2)
{
	while (amount > 0)
	{
		if (type == ROTATE2)
		{
			rot(stack1);
			rot(stack2);
			ft_printf("rr\n");
		}
		if (type == R_ROTATE2)
		{
			rrot(stack1);
			rrot(stack2);
			ft_printf("rrr\n");
		}
		if (type == SWAP2)
		{
			swap(stack1);
			swap(stack2);
			ft_printf("ss\n");
		}
		amount--;
	}
}

void	op_manager(t_op type, int amount, t_stack *stack1, t_stack *stack2)
{
	if (type == SWAP)
		operation(SWAP, amount, stack1);
	if (type == ROTATE)
		operation(ROTATE, amount, stack1);
	if (type == R_ROTATE)
		operation(R_ROTATE, amount, stack1);
	if (type == SWAP2)
		operation2(SWAP2, amount, stack1, stack2);
	if (type == ROTATE2)
		operation2(ROTATE2, amount, stack1, stack2);
	if (type == R_ROTATE2)
		operation2(R_ROTATE2, amount, stack1, stack2);
	if (type == PUSH)
	{
		while (amount-- > 0)
		{
			push(stack1, stack2);
			ft_printf("p%c\n", stack2->name);
		}
	}
}
