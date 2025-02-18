/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:22 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/13 17:26:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647L
# define INTMIN -2147483648L

// input.c
int	create_lists(int argc, char *argv[], int **stack_a, int **stack_b);
int	*atoi_arr(int argc, char *argv[]);
int	is_argvalid(char *argv[]);
int	count_args(char *argv[]);

// push_swap.c
void	swap(int *stack);
void	push(int src, int *dest, int length);
void	rot(int *stack, int length);
void	rrot(int *stack, int length);

#endif
