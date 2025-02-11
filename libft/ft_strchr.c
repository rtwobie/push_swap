/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:21:27 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 14:51:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Finds the first occurrence of c in str.
 *
 * @param str The string to search.
 * @param c The character to find.
 * @return A pointer to the first occurrence of c, or NULL if not found.
 */
char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (0);
}

/*#include <string.h>*/
/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	printf("%s\n", strchr("teste", 'e'));*/
/*	printf("%s\n", ft_strchr("teste", 'e'));*/
/*}*/
