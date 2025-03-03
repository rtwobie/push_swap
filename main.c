/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/28 21:01:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

// WARNING: remove when done!
void	print_arr(t_stack a, t_stack b, int length);

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
	if (sort(&stack_a, &stack_b) != 0)
	{
		free(stack_a.entry);
		free(stack_b.entry);
		return (1);
	}
	free(stack_a.entry);
	free(stack_b.entry);
}

// WARNING: Remember to remove .tester.c out of Makefile!
