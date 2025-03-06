/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:10:12 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:25:45 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "instruction.h"
#include "operations.h"

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
	operation2(ROTATE2, minimum, a, b);
	if (instruction->pos_a == maximum)
		operation(ROTATE, maximum - minimum, a);
	else if (instruction->pos_b == maximum)
		operation(ROTATE, maximum - minimum, b);
}

void	move_updown(t_vars *instruction, t_stack *a, t_stack *b)
{
	operation(ROTATE, instruction->pos_a, a);
	operation(R_ROTATE, b->size - instruction->pos_b, b);
}

void	move_downup(t_vars *instruction, t_stack *a, t_stack *b)
{
	operation(R_ROTATE, a->size - instruction->pos_a, a);
	operation(ROTATE, instruction->pos_b, b);
}

void	move_downdown(t_vars *instruction, t_stack *a, t_stack *b)
{
	int	second_prio;
	int	first_prio;
	int	op_on_a;
	int	op_on_b;

	op_on_a = a->size - instruction->pos_a;
	op_on_b = b->size - instruction->pos_b;
	second_prio = max(op_on_a, op_on_b);
	first_prio = min(op_on_a, op_on_b);
	operation2(R_ROTATE2, first_prio, a, b);
	if (op_on_a == second_prio)
		operation(R_ROTATE, second_prio - first_prio, a);
	else if (op_on_b == second_prio)
		operation(R_ROTATE, second_prio - first_prio, b);
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
