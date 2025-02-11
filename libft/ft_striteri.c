/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:11:08 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/04 18:47:43 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}

/*void rot(unsigned int n, char *c)*/
/*{*/
/*	(void)n;*/
/*	char	chr;*/
/*	chr = *c += 1;*/
/*}*/
/**/
/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*	char s[] = "abcdefg";*/
/*	ft_striteri(s, rot);*/
/*	printf("%s\n", s);*/
/*}*/
