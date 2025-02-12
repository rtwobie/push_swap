/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:22 by rha-le            #+#    #+#             */
/*   Updated: 2025/02/12 18:13:28 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flags
{
	SINGLE,
	MULTI,
} t_flags;

int	*create_list(int argc, char *argv[]);
int *atoi_arr(char **s, int argc, char *argv[], t_flags opt);

#endif
