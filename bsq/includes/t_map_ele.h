/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_ele.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyouki <sooyouki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:03:18 by sooyouki          #+#    #+#             */
/*   Updated: 2023/08/10 12:04:33 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_ELE_H
# define T_MAP_ELE_H

typedef struct s_map_ele
{
	int		row;
	int		col;
	int		size_sq;
	char	for_print[3];
}				t_map_ele;

#endif
