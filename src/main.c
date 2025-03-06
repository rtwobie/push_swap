/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:42:48 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"
#include "input.h"
#include "sort.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		argn;

	argn = create_lists(argc, argv, &stack_a, &stack_b);
	if (!argn || !stack_a.entry)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (argn == 1)
		return (0);
	stack_a.name = 'a';
	stack_b.name = 'b';
	stack_a.size = argn;
	stack_b.size = 0;
	if (sort(&stack_a, &stack_b) != 0)
	{
		free(stack_a.entry);
		free(stack_b.entry);
		ft_printf("Error\n");
		return (1);
	}
	free(stack_a.entry);
	free(stack_b.entry);
}
