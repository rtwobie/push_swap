/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/12 18:32:16 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

int	*create_list(int argc, char *argv[])
{
	char	**temp;
	int		*stack;
	int		i;

	i = 0;
	temp = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		stack = atoi_arr(temp, argc, argv, SINGLE);
		while (temp[i])
			free(temp[i++]);
		free(temp);
	}
	else
		stack = atoi_arr(temp, argc, argv, MULTI);
	return (stack);
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	i;

	i = 0;
	if (argc == 1)
		return (1);
	stack_a = create_list(argc, argv);
	if (stack_a == NULL)
		return (1);
	while (stack_a[i])
	{
		ft_printf("%i\n", stack_a[i]);
		i++;
	}
	free(stack_a);
}
