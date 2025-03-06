/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:17:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/06 19:25:36 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"
#include "libft.h"
#include "input.h"

#define INTMAX 2147483647LL
#define INTMIN -2147483648LL

int	is_argvalid(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		while (ft_isspace(arg[i]))
			i++;
		if (arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		while (ft_isdigit(arg[i]))
			i++;
		if (!(ft_isspace(arg[i]) || arg[i] == '\0'))
			return (0);
	}
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	is_inputvalid(char *argv[])
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!is_argvalid(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

t_elem	*atoi_arr(int argc, char *argv[])
{
	t_elem	*stack;
	int		i;

	stack = (t_elem *) ft_calloc(sizeof(t_elem), argc);
	if (!stack)
		return (NULL);
	i = -1;
	while (++i < argc)
	{
		if (ft_atoll(argv[i]) > INTMAX || ft_atoll(argv[i]) < INTMIN)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		stack[i].val = ft_atoi(argv[i]);
	}
	return (stack);
}

int	create_lists(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char	**args;
	int		argn;

	if (argc == 1)
		return (0);
	args = argv + 1;
	argn = argc - 1;
	if (!is_inputvalid(args))
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argn = count_args(args);
	}
	a->entry = atoi_arr(argn, args);
	if (!a->entry)
		return (0);
	if (argn == 1)
		return (argn);
	b->entry = (t_elem *) ft_calloc(sizeof(t_elem), argn);
	if (!b->entry)
		return (0);
	if (argc == 2)
		free_args(args);
	return (argn);
}
