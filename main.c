/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 02:17:11 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

// WARNING: remove when done!
void	print_arr(t_stack *a, t_stack *b, int length)
{
	int i = 0;

	while (i < length)
	{
		ft_printf("a: [num= %i, idx= %i]\t", a->entry[i].val, a->entry[i].idx);
		ft_printf("b: [num= %i, idx= %i]\n", b->entry[i].val, b->entry[i].idx);
		i++;
	}
	ft_printf("\ncurrent size: [%i]\t[%i]\n", a->size, b->size);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		argn;

	argn = create_lists(argc, argv, &stack_a.entry, &stack_b.entry);
	if (!argn || !stack_a.entry)
		return (1);
	stack_a.name = 'a';
	stack_a.size = argn;
	stack_b.name = 'b';
	stack_b.size = 0;
	print_arr(&stack_a, &stack_b, argn);
	if (sort(&stack_a, &stack_b) != 0)
	{
		free(stack_a.entry);
		free(stack_b.entry);
		return (1);
	}
	print_arr(&stack_a, &stack_b, argn);
	free(stack_a.entry);
	free(stack_b.entry);
}
