/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:49 by rha-le            #+#    #+#             */
/*   Updated: 2024/11/26 17:29:13 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

/**
 * NOTE: i will always be = destsize, unless size < destsize
 *		 which will mean unless size is not bigger than destsize + 1 (NUL)
 *		 then it will not go into the while
 *
 *		 conclusion:
 *		 when using ft_strlcat,
 *		 size should always be bigger than destsize including the NUL-Byte
 */
