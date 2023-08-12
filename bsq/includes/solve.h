/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:23:18 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 12:09:18 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <unistd.h>
# include "t_map_ele.h"
# include "allocation.h"
# include "dp.h"
# include "init_map.h"

# define EMPTY 0
# define OBST 1
# define SQR 2

void	solve(char *file_name);
void	fill_square(char **map_char, int y, int x, t_map_ele element);
void	print_square(char **map_char, int row, int col);
void	prefix_map(int **map, int row, int col);
void	find_right_bottom(int **map, int *y, int *x, t_map_ele *element);

#endif
