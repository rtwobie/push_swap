/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:07 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/06 18:58:50 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "defs.h"

int		is_argvalid(char *arg);
int		is_inputvalid(char **arguments);
t_elem	*atoi_arr(int arg_count, char **arguments);
int		create_lists(int argc, char *argv[], t_stack *a, t_stack *b);

int		count_args(char **arguments);
void	free_args(char **arguments);

#endif // !INPUT_H
