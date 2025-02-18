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

void	push(int src, int *dest, int length)
{
	ft_realloc(dest, sizeof(int) * (length + 1));
	if (!dest)
		return ;
	while (length--)
		dest[length + 1] = dest[length];
	dest[0] = src;
}

int	main(int argc, char *argv[])
{
	int *arr;
	int i = 0;

	arr = (int *) malloc(sizeof(int) * 3);
	while (++i <= 3)
		arr[i] = i;
	return (0);
}
