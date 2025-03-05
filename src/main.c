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
#include "sort_utils.h"
#include "operations.h"

int	create_lists(int argc, char *argv[], t_elem **stack_a, t_elem **stack_b)
{
	char	**args;
	int		argn;

	if (argc == 1)
		return (0);
	args = argv + 1;
	argn = argc - 1;
	if (!is_argvalid(args))
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argn = count_args(args);
	}
	*stack_a = atoi_arr(argn, args);
	*stack_b = (t_elem *) ft_calloc(sizeof(t_elem), argn);
	if (!*stack_b)
		return (0);
	if (argc == 2)
		free_args(args);
	return (argn);
}

int	sort(t_stack *a, t_stack *b)
{
	int	i;

	if (indexing(a) != 0)
		return (1);
	if (is_sorted(a) || a->size < 3)
	{
		rot_to_top(a, find_smallest(a));
		return (0);
	}
	if (a->size == 4)
		op_manager(PUSH, 1, a, b);
	else if (a->size >= 5)
		op_manager(PUSH, 2, a, b);
	i = a->size;
	while (i > 3)
	{
		move_manager(a, b);
		op_manager(PUSH, 1, a, b);
		i--;
	}
	sort_three(a);
	rot_to_top(b, find_biggest(b));
	push_back(a, b);
	rot_to_top(a, find_smallest(a));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		argn;

	argn = create_lists(argc, argv, &stack_a.entry, &stack_b.entry);
	if (!argn || !stack_a.entry)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a.name = 'a';
	stack_a.size = argn;
	stack_b.name = 'b';
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
