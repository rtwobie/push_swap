/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/17 16:11:22 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

void	print_arr(struct s_stack stack, int length, char c)
{
	int	i;

	i = 0;
	while (i < length)
	{
		ft_printf("%c: %i\t", c, stack.entry[i].num);
		i++;
	}
	ft_printf("\nsize: %i\n\n", stack.size);
}

int	main(int argc, char *argv[])
{
	struct s_stack stack_a;
	struct s_stack stack_b;
	int			argn;

	argn = create_lists(argc, argv, &stack_a.entry, &stack_b.entry);
	if (!argn || !stack_a.entry)
	{
		ft_printf("creating lists failed\n");
		return (1);
	}

	stack_a.size = argn;
	stack_b.size = 0;

	ft_printf("before\n");
	print_arr(stack_a, argn, 'a');

	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	rot(stack_b);
	push(&stack_a, &stack_b);
	swap(stack_b.entry);

	ft_printf("after\n");
	print_arr(stack_a, argn, 'a');
	print_arr(stack_b, argn, 'b');

	free(stack_a.entry);
	free(stack_b.entry);
}
