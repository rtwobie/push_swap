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

int	*atoi_arr(int argc, char *argv[])
{
	int	*stack;
	int	i;

	i = -1;
	stack = (int *) malloc(sizeof(int) * argc);
	if (!stack)
		return (NULL);
	while (++i < argc)
	{
		if (ft_atol(argv[i]) > INTMAX || ft_atol(argv[i]) < INTMIN)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		stack[i] = ft_atoi(argv[i]);
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

int	*create_list(int argc, char *argv[])
{
	char	**args;
	int		argn;
	int		*stack;

	if (argc == 1)
		return (NULL);
	args = argv + 1;
	argn = argc - 1;
	if (!is_argvalid(args))
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argn = count_args(args);
	}
	stack = atoi_arr(argn, args);
	if (argc == 2)
		free_args(args);
	return (stack);
}
