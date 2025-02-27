/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/27 19:46:48 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

// WARNING: remove when done!
void	print_arr(t_stack a, t_stack b, int length);
void	OP_TESTER(t_stack stack_a, t_stack stack_b, int argn);
int calc_pos_b(int idx_a, t_stack b);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int				argn;

	argn = create_lists(argc, argv, &stack_a.entry, &stack_b.entry);
	if (!argn || !stack_a.entry)
	{
		ft_printf("creating lists failed\n");
		return (1);
	}
	stack_a.name = 'a';
	stack_a.size = argn;
	stack_b.name = 'b';
	stack_b.size = 0;
	sort(stack_a, stack_b);
	op_manager(PUSH, 3, &stack_a, &stack_b);
	print_arr(stack_a, stack_b, argn);
	for (int i = 0; i < stack_a.size; i++)
		ft_printf("--- [pos_b: %i] ---\n", calc_pos_b(stack_a.entry[i].idx, stack_b));


	free(stack_a.entry);
	free(stack_b.entry);
}

// WARNING: Remember to remove .tester.c out of Makefile!
