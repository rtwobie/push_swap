/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:44:58 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/06 20:12:33 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	count_args(char **arguments)
{
	size_t	i;

	i = 0;
	while (arguments[i])
		i++;
	return (i);
}

void	free_args(char **arguments)
{
	size_t	i;

	i = 0;
	while (arguments[i])
		free(arguments[i++]);
	free(arguments);
}
