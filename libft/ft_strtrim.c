/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:53:08 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/02 22:47:59 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	int		start;
	int		end;
	char	*res;

	start = 0;
	end = ft_strlen(s);
	while (ft_strchr(set, s[start]))
		start++;
	while (ft_strchr(set, s[end]))
		end--;
	res = ft_substr(s, start, (end - start + 1));
	return (res);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char *test = "ababaaaMy name is Simonbbaaabba";*/
/*	printf("%s\n", "ft_strtrim(\"ababaaaMy name is Simonbbaaabba\", \"ab\")");*/
/*	printf("%s\n", ft_strtrim(test, "ab"));*/
/**/
/*	char *test2 = "";*/
/*	printf("%s\n", "ft_strtrim(\"\", \"ab\")");*/
/*	printf("%s\n", ft_strtrim(test2, "ab"));*/
/**/
/*	char *test3 = "Hello World";*/
/*	printf("%s\n", "ft_strtrim(\"Hello World\", \"\")");*/
/*	printf("%s\n", ft_strtrim(test3, "ab"));*/
/**/
/*	char *test4 = "";*/
/*	printf("%s\n", "ft_strtrim(\"\", \"\")");*/
/*	printf("%s\n", ft_strtrim(test4, "ab"));*/
/*}*/

/* NOTE:
 *		in:  ababaaaMy name is Simonbbaaabbad, ab
 *		out: My name is Simon
 */

/* QUEST:
 *		[ ] get start;
 *		[ ] get end;
 */
