/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:12 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/03 15:47:16 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* NOTE:
 * direction (up,up) -> cost = max(pos_a, pos_b)
 * direction (up,down) -> cost = pos_a + (b.size - pos_b)
 * direction (down,up) -> cost = (a.size - pos_a) + pos_b
 * direction (up,up) -> cost = max(a.size - pos_a, b.size - pos_b)
 */

void	move_upup(t_vars *instruction, t_stack *a, t_stack *b)
{
	int		maximum;
	int		minimum;

	maximum = max(instruction->pos_a, instruction->pos_b);
	minimum = min(instruction->pos_a, instruction->pos_b);
	op_manager(ROTATE2, minimum, a, b);
	if (instruction->pos_a == maximum)
		op_manager(ROTATE, maximum - minimum, a, b);
	else if (instruction->pos_b == maximum)
		op_manager(ROTATE, maximum - minimum, b, a);
}

void	move_updown(t_vars *instruction, t_stack *a, t_stack *b)
{
	op_manager(ROTATE, instruction->pos_a, a, b);
	op_manager(R_ROTATE, b->size - instruction->pos_b, b, a);
}

void	move_downup(t_vars *instruction, t_stack *a, t_stack *b)
{
	op_manager(R_ROTATE, a->size - instruction->pos_a, a, b);
	op_manager(ROTATE, instruction->pos_b, b, a);
}

void	move_downdown(t_vars *instruction, t_stack *a, t_stack *b)
{
	int	maximum;
	int	minimum;

	maximum = max(a->size - instruction->pos_a, b->size - instruction->pos_b);
	minimum = min(a->size - instruction->pos_a, b->size - instruction->pos_b);
	op_manager(R_ROTATE2, minimum, a, b);
	if (instruction->pos_a == maximum)
		op_manager(R_ROTATE, maximum - minimum, a, b);
	else if (instruction->pos_b == maximum)
		op_manager(R_ROTATE, maximum - minimum, b, a);
}

void	move_manager(t_stack *a, t_stack *b)
{
	t_vars	instruction;

	if (build_instruction(&instruction, a, b) != 0)
		return ;
	if (instruction.direction == 0)
		move_upup(&instruction, a, b);
	if (instruction.direction == 1)
		move_updown(&instruction, a, b);
	if (instruction.direction == 2)
		move_downup(&instruction, a, b);
	if (instruction.direction == 3)
		move_downdown(&instruction, a, b);
}
