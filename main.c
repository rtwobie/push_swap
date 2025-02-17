/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/17 16:11:22 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	int		i;

	i = 0;
	if (create_lists(argc, argv, &stack_a, &stack_b) == -1)
		return (1);
	if (stack_a == NULL)
		return (1);
	ft_printf("before\n");
	while (stack_a[i])
	{
		ft_printf("a: %i\n", stack_a[i]);
		i++;
	}
	stack_b[0] = 99;
	ft_printf("b: %i\n", stack_b[0]);
	ft_printf("after\n");
	push(stack_b, stack_a);
	/*i = 0;*/
	/*while (stack_a[i])*/
	/*{*/
	/*	ft_printf("a: %i\n", stack_a[i]);*/
	/*	i++;*/
	/*}*/
	free(stack_a);
	free(stack_b);
}
