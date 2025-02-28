/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tester.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/28 17:47:46 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_arr(t_stack a, t_stack b, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		ft_printf("a: [num= %i, index= %i]\t", a.entry[i].val, a.entry[i].idx);
		ft_printf("b: [num= %i, index= %i]\n", b.entry[i].val, b.entry[i].idx);
		i++;
	}
	ft_printf("\nsize: %i\t%i\n\n", a.size, b.size);
}

void	OP_TESTER(t_stack stack_a, t_stack stack_b, int argn)
{
	print_arr(stack_a, stack_b, argn);

	op_manager(SWAP, 1, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	op_manager(PUSH, 3, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	op_manager(ROTATE2, 1, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	op_manager(R_ROTATE2, 1, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	op_manager(SWAP, 1, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	op_manager(PUSH, 3, &stack_b, &stack_a);
	print_arr(stack_a, stack_b, argn);
}

