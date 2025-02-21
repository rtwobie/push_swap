/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:22 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/20 21:12:52 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647L
# define INTMIN -2147483648L
# define ROTATE 0
# define R_ROTATE 1

typedef struct s_elem
{
	int	num;
	int	index;
} t_elem;

struct s_stack
{
	t_elem	*entry;
	int		size;
};

// input.c
int		create_lists(int argc, char *argv[], t_elem **stack_a, t_elem **stack_b);
t_elem	*atoi_arr(int argc, char *argv[]);
int		is_argvalid(char *argv[]);
int		count_args(char *argv[]);

// push_swap.c
void	swap(t_elem *stack);
void	push(struct s_stack *src, struct s_stack *dest);
void	rrot(struct s_stack stack, char name);
void	rot(struct s_stack stack, char name);

// sort.c
void	sort(struct s_stack a, struct s_stack b);
int		indexing(t_elem *a, int size);
int		calc_ops(struct s_stack stack, int entry_position, int *direction);
//void	ft(struct s_stack stack, char name, int entry_position);

#endif
