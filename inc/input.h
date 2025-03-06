/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:07 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/05 17:20:49 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "defs.h"

int		is_argvalid(char *argv[]);
int		count_args(char *argv[]);
t_elem	*atoi_arr(int argc, char *argv[]);
void	free_args(char *args[]);
int		create_lists(int argc, char *argv[], t_stack *a, t_stack *b);

#endif // !INPUT_H
