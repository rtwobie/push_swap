/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/13 17:25:40 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		i;

	i = 0;
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
