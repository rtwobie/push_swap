/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:17:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:42:24 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"
#include "libft.h"

#define INTMAX 2147483647L
#define INTMIN -2147483648L

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
	stack = (t_elem *) ft_calloc(sizeof(t_elem), argc);
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
		stack[i].val = ft_atoi(argv[i]);
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
