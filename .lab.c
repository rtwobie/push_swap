/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:53:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/13 16:03:25 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft/libft.h"

int	is_argvalid(char *argv[])
{
	size_t	i;
	size_t	j;
	int		valid;

	i = 1;
	j = 0;
	valid = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				valid = 0;
			j++;
		}
		i++;
	}
	return (valid);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("not enough args\n");
		return (1);
	}
	if (is_argvalid(argv) == 0)
	{
		printf("input is invalid\n");
		return (1);
	}
	printf("input is valid\n");
	return (0);
}
