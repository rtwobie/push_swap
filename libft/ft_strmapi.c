/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:40:38 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/04 18:03:14 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*char rot(unsigned int n, char c)*/
/*{*/
/*	(void)n;*/
/*	char	chr;*/
/*	chr = c += 1;*/
/*	return (chr);*/
/*}*/
/**/
/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	char *s = ft_strmapi("abcdefg", rot);*/
/*	printf("%s\n", s);*/
/*}*/
