/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:22 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/03 15:42:11 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

# define INTMAX 2147483647L
# define INTMIN -2147483648L

typedef enum e_op
{
	SWAP,
	SWAP2,
	ROTATE,
	ROTATE2,
	R_ROTATE,
	R_ROTATE2,
	PUSH,
}	t_op;

typedef struct s_vars
{
	int	pos_a;
	int	pos_b;
	int	operations;
	int	direction;
}	t_vars;

typedef struct s_elem
{
	int	val;
	int	idx;
}	t_elem;

typedef struct s_stack
{
	char	name;
	int		size;
	t_elem	*entry;
}	t_stack;

// input.c
int		create_lists(int argc, char *argv[], t_elem **a, t_elem **b);
t_elem	*atoi_arr(int argc, char *argv[]);
int		is_argvalid(char *argv[]);
int		count_args(char *argv[]);

// operations.c
void	swap(t_stack stack);
void	push(t_stack *src, t_stack *dest);
void	rrot(t_stack stack);
void	rot(t_stack stack);

// operation_manager.c
void	swap_manager(t_stack *stack1, t_stack *stack2, t_op type);
void	rot_manager(t_stack *stack1, t_stack *stack2, t_op type);
void	op_manager(t_op type, int amount, t_stack *src, t_stack *dest);

// sort.c
int		sort(t_stack *a, t_stack *b);
int		indexing(t_stack *a);
int		calc_pos(t_stack stack, int entry_position, t_op *direction);

// calc_operations.c
int		calc_pos_b(int idx_a, t_stack *b);
void	choose_direction(t_vars *instruction, t_elem *direction);
t_vars	get_direction(int pos_a, int size_a, int pos_b, int size_b);
int		build_instruction(t_vars *best, t_stack *a, t_stack *b);

//move.c
void	move_manager(t_stack *a, t_stack *b);

//utils_op.c
t_elem	up_bound(t_elem up_bnd, int pos_b, int current_idx, int idx_a);
t_elem	low_bound(t_elem low_bnd, int pos_b, int current_idx, int idx_a);
int		max(int nb1, int nb2);
int		min(int nb1, int nb2);

#endif
