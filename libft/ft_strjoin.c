/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:33:40 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/02 22:47:59 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	char	*s;

	if (!str1 && !str2)
		return (ft_strdup(""));
	s = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*str1)
	{
		s[i] = *str1;
		i++;
		str1++;
	}
	while (*str2)
	{
		s[i] = *str2;
		i++;
		str2++;
	}
	s[i] = '\0';
	return (s);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	char *str = ft_strjoin("Hello ", "World!");*/
/*	printf("%s\n", "ft_strjoin(\"Hello\", \" World!\")");*/
/*	printf("%s\n", str);*/
/**/
/*	char *str2 = ft_strjoin("Hello", "");*/
/*	printf("%s\n", "ft_strjoin(\"Hello\", \"\")");*/
/*	printf("%s\n", str2);*/
/**/
/*	char *str3 = ft_strjoin("", "World!");*/
/*	printf("%s\n", "ft_strjoin(\"\", \"World!\")");*/
/*	printf("%s\n", str3);*/
/**/
/*	char *str4 = ft_strjoin("", "");*/
/*	printf("%s\n", "ft_strjoin(\"\", \"\")");*/
/*	printf("%s\n", str4);*/
/*}*/
