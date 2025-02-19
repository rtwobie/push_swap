/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:17:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/13 18:02:30 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int	is_argvalid(char *argv[])
{
	size_t	i;
	size_t	j;
	int		valid;

	i = 0;
	j = 0;
	valid = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' \
				&& argv[i][j] != '-')
				valid = 0;
			j++;
		}
		i++;
	}
	return (valid);
}

int	count_args(char *argv[])
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_elem	*atoi_arr(int argc, char *argv[])
{
	t_elem	*stack;
	int		i;

	i = -1;
	stack = (t_elem *) malloc(sizeof(t_elem) * argc);
	if (!stack)
	{
		ft_printf("stack creation failed\n");
		return (NULL);
	}
	while (++i < argc)
	{
		if (ft_atol(argv[i]) > INTMAX || ft_atol(argv[i]) < INTMIN)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		stack[i].num = ft_atoi(argv[i]);
	}
	return (stack);
}

void	free_args(char *args[])
{
	size_t	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

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
	*stack_b = (t_elem *) malloc(sizeof(t_elem) * argn);
	if (!*stack_b)
		return (0);
	if (argc == 2)
		free_args(args);
	return (argn);
}
