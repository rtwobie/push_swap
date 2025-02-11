/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:18:05 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/04 17:17:43 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*alloc_nbr(char *s, long n, int size_n)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		s++;
	}
	while (size_n >= 0)
	{
		s[size_n] = (n % 10) + '0';
		n /= 10;
		size_n--;
	}
	if (n < 0)
		s--;
	return (s);
}

static int	digitlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		size_n;

	sign = 0;
	if (n < 0)
		sign = 1;
	size_n = digitlen(n);
	res = (char *) malloc(sizeof(char) * (sign + size_n + 1));
	if (!res)
		return (NULL);
	alloc_nbr(res, n, (size_n - 1));
	res[sign + size_n] = '\0';
	return (res);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	char *s[3];*/
/*	s[0] = ft_itoa(2147483647);*/
/*	s[1] = ft_itoa(-2147483648);*/
/*	s[2] = ft_itoa(0);*/
/*	printf("%s\n", s[0]);*/
/*	printf("%s\n", s[1]);*/
/*	printf("%s\n", s[2]);*/
/*	free(s[0]);*/
/*	free(s[1]);*/
/*	free(s[2]);*/
/*}*/
