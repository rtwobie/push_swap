/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:42:34 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:01:45 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

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

#endif // !DEFS_H
