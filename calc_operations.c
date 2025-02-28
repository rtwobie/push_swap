/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:06:30 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/28 21:20:40 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	calc_pos_b(int idx_a, t_stack *b)
{
	int		pos_b;
	t_elem	up_bnd;
	t_elem	low_bnd;

	pos_b = 0;
	up_bnd.idx = INT_MAX;
	low_bnd.idx = 0;
	while (pos_b < b->size)
	{
		up_bnd = up_bound(up_bnd, pos_b, b->entry[pos_b].idx, idx_a);
		low_bnd = low_bound(low_bnd, pos_b, b->entry[pos_b].idx, idx_a);
		pos_b++;
	}
	if (up_bnd.idx == INT_MAX)
	{
		up_bnd.idx = idx_a;
		up_bnd.val = low_bnd.val - 1;
	}
	if (low_bnd.idx == 0 && up_bnd.val == b->size - 1)
		low_bnd.val = 0;
	else if (low_bnd.idx == 0)
		low_bnd.val = up_bnd.val + 1;
	/*ft_printf("\na index = %i\n", idx_a);*/
	/*ft_printf("High Pos: %i\t High Index: %i\n", up_bnd.val, up_bnd.idx);*/
	/*ft_printf("Low Pos: %i\t Low Index: %i\n", low_bnd.val, low_bnd.idx);*/
	return (low_bnd.val);
}

t_vars	best_direction(int pos_a, int size_a, int pos_b, int size_b)
{
	int		i;
	t_vars	instruction;
	t_elem	direction[4];

	i = -1;
	while (++i < 4)
		direction[i].idx = i;
	direction[0].val = max(pos_a, pos_b) + 1;
	direction[1].val = pos_a + (size_b - pos_b) + 1;
	direction[2].val = (size_a - pos_a) + pos_b + 1;
	direction[3].val = max(size_a - pos_a, size_b - pos_b) + 1;
	instruction.operations = direction[0].val;
	instruction.direction = direction[0].idx;
	i = 1;
	while (i < 4)
	{
		if (instruction.operations > direction[i].val)
		{
			instruction.operations = direction[i].val;
			instruction.direction = direction[i].idx;
		}
		i++;
	}
	return (instruction);
}

int	build_instruction(t_vars *best, t_stack *a, t_stack *b)
{
	int		i;
	int		pos_b;
	t_vars	*instructions;

	instructions = (t_vars *) malloc(sizeof(t_vars) * a->size);
	if (!instructions)
		return (1);
	i = -1;
	while (++i < a->size)
	{
		pos_b = calc_pos_b(a->entry[i].idx, b);
		instructions[i] = best_direction(i, a->size, pos_b, b->size);
		instructions[i].pos_a = i;
		instructions[i].pos_b = pos_b;
	}
	*best = instructions[0];
	i = -1;
	while (++i < a->size)
	{
		if (best->operations > instructions[i].operations)
			*best = instructions[i];
	}
	free(instructions);
	return (0);
}

void	move(t_stack *a, t_stack *b)
{
	int		major;
	int		minor;
	t_vars	instruction;

	if (build_instruction(&instruction, a, b) == 1)
		return ;
	major = max(instruction.pos_a, instruction.pos_b);
	minor = min(instruction.pos_a, instruction.pos_b);
	if (instruction.direction == 0)
	{
		op_manager(ROTATE2, minor, a, b);
		op_manager(ROTATE, major - minor, x, x); // TODO: has to know depending on major/minor
	}
	if (instruction.direction == 1)
	if (instruction.direction == 2)
	if (instruction.direction == 3)
	ft_printf("pos_a:\t%i\n", instruction.pos_a);
	ft_printf("pos_b:\t%i\n", instruction.pos_b);
	ft_printf("operations:\t%i\n", instruction.operations);
	ft_printf("direction:\t%i\n", instruction.direction);
}
