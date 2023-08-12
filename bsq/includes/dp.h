/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:37:16 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 12:02:23 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DP_H
# define DP_H

# include "solve.h"

int		get_min(int lb, int lt, int rt);
void	prefix_map(int **map, int row, int col);
void	find_right_bottom(int **map, int *y, int *x, t_map_ele *element);

#endif
