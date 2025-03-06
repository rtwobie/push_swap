/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/06 19:24:53 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"
#include "input.h"
#include "sort.h"

void	init_stacks(t_stack *a, t_stack *b, int size)
{
	a->name = 'a';
	b->name = 'b';
	a->size = size;
	b->size = 0;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		argn;

	if (argc == 1)
		return (1);
	argn = create_lists(argc, argv, &stack_a, &stack_b);
	if (!argn)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (argn == 1)
		return (0);
	init_stacks(&stack_a, &stack_b, argn);
	if (sort(&stack_a, &stack_b) != 0)
	{
		free(stack_a.entry);
		free(stack_b.entry);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	free(stack_a.entry);
	free(stack_b.entry);
}
