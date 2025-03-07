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

int	is_inputvalid(char **arguments)
{
	size_t	i;

	i = 0;
	while (arguments[i])
	{
		if (!is_argvalid(arguments[i]))
			return (0);
		if (ft_atoll(arguments[i]) > INTMAX || \
			ft_atoll(arguments[i]) < INTMIN)
			return (0);
		i++;
	}
	return (1);
}

t_elem	*atoi_arr(int arg_count, char **arguments)
{
	t_elem	*stack;
	int		i;

	stack = (t_elem *) ft_calloc(sizeof(t_elem), arg_count);
	if (!stack)
		return (NULL);
	i = -1;
	while (++i < arg_count)
		stack[i].val = ft_atoi(arguments[i]);
	return (stack);
}

int	create_lists(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char	**arguments;
	int		arg_count;

	if (argc == 1)
		return (0);
	arguments = argv + 1;
	arg_count = argc - 1;
	if (!is_inputvalid(arguments))
		return (0);
	if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		arg_count = count_args(arguments);
	}
	a->entry = atoi_arr(arg_count, arguments);
	if (!a->entry)
		return (0);
	if (argc == 2)
		free_args(arguments);
	b->entry = (t_elem *) ft_calloc(sizeof(t_elem), arg_count);
	if (!b->entry)
		return (0);
	return (arg_count);
}
