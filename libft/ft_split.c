/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:05:50 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/03 13:21:54 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**malloc_arr(const char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (!ft_strchr(&c, s[i]) && \
			(s[i + 1] == c || s[i + 1] == '\0'))
			size++;
		i++;
	}
	arr = (char **) malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

static char	*skip_delimiter(char *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static char	**free_on_error(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	end;

	res = malloc_arr(s, c);
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		s = skip_delimiter((char *)s, c);
		if (*s == '\0')
			break ;
		end = 0;
		while (s[end] && s[end] != c)
			end++;
		res[i] = ft_substr(s, 0, end);
		if (!res[i])
			return (free_on_error(res));
		i++;
		s += end;
	}
	res[i] = NULL;
	return (res);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	int	i = 0;*/
/*	char **arr = ft_split("hallo#hi#jo", '#');*/
/*	char **arr = ft_split("      split       this for   me  !       ", '#');*/
/*	while (arr[i])*/
/*	{*/
/*		printf("%s\n", arr[i]);*/
/*		i++;*/
/*	}*/
/*	printf("%s\n", arr[i]);*/
/*	free_on_error(arr);*/
/*}*/
