/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:14:24 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/12 18:20:18 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int *atoi_arr(char **s, int argc, char *argv[], t_flags opt)
{
	int	*stack;
	int	i;

	i = 0;
	if (opt == SINGLE)
	{
		while (s[i] != NULL)
			i++;
		stack = (int *) malloc(sizeof(int) * i);
		if (!stack)
			return (NULL);
		i = -1;
		while (s[++i] != NULL)
			stack[i] = ft_atoi(s[i]);
	}
	if (opt == MULTI)
	{
		stack = (int *) malloc(sizeof(int) * argc);
		if (!stack)
			return (NULL);
		while (++i < argc)
			stack[i - 1] = ft_atoi(argv[i]);
	}
	return (stack);
}
