/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:06:01 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/02 21:27:00 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*substr;

	if (start >= (unsigned int)ft_strlen(str))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(str + start))
		len = (unsigned int)ft_strlen(str + start);
	substr = (char *)malloc(sizeof(*str) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start && j < len)
		{
			substr[j] = str[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	char *sub = ft_substr("Bonjour comment ca va?", 5, 8);*/
/*	printf("%s\n", sub);*/
/*	free(sub);*/
/*}*/

/* QUESTION:
 *		ln. 23: Why empty string and not NULL?
 */

/* NOTE:
 *		ln. 24: handles exceeding len value
 *				if bigger than ft_strlen(str + start).
 */
