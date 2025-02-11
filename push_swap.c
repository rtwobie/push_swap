/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/11 17:34:39 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stddef.h>

int	create_list(int argc, char *argv[], char ***args)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (-1);
	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		*args = (char **) malloc(sizeof(char *) * argc);
		if (!args)
			return (-1);
		while (++i < argc)
			*args[i - 1] = argv[i];
		*args[argc] = NULL;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**args;

	if (create_list(argc, argv, &args) == -1)
		return (1);
	int i = 0;
	while (args[i])
	{
		ft_printf("%s\n");
	}
}
