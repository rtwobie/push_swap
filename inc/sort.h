/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:37:30 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 18:41:57 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "defs.h"

int		indexing(t_stack *a);
void	rot_to_top(t_stack *stack, int pos);
void	push_back(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	move_manager(t_stack *a, t_stack *b);

#endif // !SORT_H
