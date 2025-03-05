/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:53:11 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:34:45 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "defs.h"

typedef struct s_vars
{
	int	pos_a;
	int	pos_b;
	int	operations;
	int	direction;
}	t_vars;

// instruction.c
int		calc_pos_b(int idx_a, t_stack *b);
void	choose_direction(t_vars *instruction, t_elem *direction);
t_vars	get_direction(int pos_a, int size_a, int pos_b, int size_b);
int		build_instruction(t_vars *best, t_stack *a, t_stack *b);

//move_utils.c
t_elem	up_bound(t_elem up_bnd, int pos_b, int current_idx, int idx_a);
t_elem	low_bound(t_elem low_bnd, int pos_b, int current_idx, int idx_a);
int		max(int nb1, int nb2);
int		min(int nb1, int nb2);

#endif // !INSTRUCTION_H
