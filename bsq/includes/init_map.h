/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:50:19 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 11:57:10 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MAP_H
# define INIT_MAP_H

# include <unistd.h>
# include "solve.h"
# include "allocation.h"

int		get_element(char *file_name, t_map_ele *target);
int		get_row(int fd, char *temp);
void	init_map(char *file_name, int **map, \
		char **map_char, t_map_ele element);
void	convert_c_to_i(int *dest_arr, char *src_arr, int col, char *for_print);
void	copy_f_to_c(char *dest_arr, char *src_arr, int col);

#endif
