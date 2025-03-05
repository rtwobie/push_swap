/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:00:50 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:01:59 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "defs.h"

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

// operations.c
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rrot(t_stack *stack);
void	rot(t_stack *stack);

// operation_manager.c
void	operation(t_op type, int amount, t_stack *stack);
void	operation2(t_op type, int amount, t_stack *stack1, t_stack *stack2);
void	op_manager(t_op type, int amount, t_stack *stack1, t_stack *stack2);

#endif // !OPERATIONS_H
