/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:22 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/22 17:46:16 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_elem
{
	int	num;
	int	index;
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
void	swap_manager(t_stack stack1, t_stack stack2, t_op type);
void	rot_manager(t_stack stack1, t_stack stack2, t_op type);
void	op_manager(t_op type, int amount, t_stack *src, t_stack *dest);

// sort.c
void	sort(t_stack a, t_stack b);
int		indexing(t_elem *a, int size);
int		calc_ops(t_stack stack, int entry_position, t_op *direction);
//void	ft(struct s_stack stack, char name, int entry_position);

#endif
