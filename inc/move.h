/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:32:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:35:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "defs.h"
# include "instruction.h"

void	move_upup(t_vars *instruction, t_stack *a, t_stack *b);
void	move_updown(t_vars *instruction, t_stack *a, t_stack *b);
void	move_downup(t_vars *instruction, t_stack *a, t_stack *b);
void	move_downdown(t_vars *instruction, t_stack *a, t_stack *b);

#endif // !MOVE_H
