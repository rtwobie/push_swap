/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:17:06 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/04 20:52:05 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	operation(t_stack *stack, t_op type)
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
}

void	operation2(t_stack *stack1, t_stack *stack2, t_op type)
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
	if (type == PUSH)
	{
		push(stack1, stack2);
		ft_printf("p%c\n", stack2->name);
	}
}

void	op_manager(t_op type, int amount, t_stack *stack1, t_stack *stack2)
{
	while (amount > 0)
	{
		if (type == SWAP)
			operation(stack1, SWAP);
		if (type == ROTATE)
			operation(stack1, ROTATE);
		if (type == R_ROTATE)
			operation(stack1, R_ROTATE);
		if (type == SWAP2)
			operation2(stack1, stack2, SWAP2);
		if (type == ROTATE2)
			operation2(stack1, stack2, ROTATE2);
		if (type == R_ROTATE2)
			operation2(stack1, stack2, R_ROTATE2);
		if (type == PUSH)
			operation2(stack1, stack2, PUSH);
		amount--;
	}
}
