/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:11:27 by rha-le            #+#    #+#             */
/*   Updated: 2024/11/11 13:21:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	printf("atoi\n");*/
/*	printf("\nin: %s\t out: %d\n", "-2147483648", atoi("-2147483648"));*/
/*	printf("\nin: %s\t out: %d\n", "2147483647", atoi("2147483647"));*/
/*	printf("\nin: %s\t out: %d\n", "\\t\\v\\r 123", atoi("\t\f\v\r 123"));*/
/*	printf("\nin: %s\t out: %d\n", "--123", atoi("--123"));*/
/*	printf("\nin: %s\t out: %d\n", "+123", atoi("+123"));*/
/*	printf("\nin: %s\t out: %d\n", "abc", atoi("abc"));*/
/*	printf("\nin: %s\t out: %d\n", "123a4", atoi("123a4"));*/
/**/
/*	printf("ft_atoi\n");*/
/*	printf("\nin: %s\t out: %d\n", "-2147483648", ft_atoi("-2147483648"));*/
/*	printf("\nin: %s\t out: %d\n", "2147483647", ft_atoi("2147483647"));*/
/*	printf("\nin: %s\t out: %d\n", "\\t\\v\\r 123", ft_atoi("\t\f\v\r 123"));*/
/*	printf("\nin: %s\t out: %d\n", "--123", ft_atoi("--123"));*/
/*	printf("\nin: %s\t out: %d\n", "+123", ft_atoi("+123"));*/
/*	printf("\nin: %s\t out: %d\n", "abc", ft_atoi("abc"));*/
/*	printf("\nin: %s\t out: %d\n", "123a4", ft_atoi("123a4"));*/
/*}*/
