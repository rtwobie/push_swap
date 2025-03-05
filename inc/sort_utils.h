/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:28 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:31:44 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "defs.h"

int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
int		is_sorted(t_stack *a);

#endif // !SORT_H
