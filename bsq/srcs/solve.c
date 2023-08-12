/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:42 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 12:11:02 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

void	solve(char *file_name)
{
	t_map_ele	element;
	int			**map;
	char		**map_char;
	int			y;
	int			x;

	if (get_element(file_name, &element) == 0)
		return ;
	map = alloc_map(element.row, element.col);
	map_char = alloc_map_char(element.row, element.col);
	if (map == 0)
	{
		return ;
	}
	init_map(file_name, map, map_char, element);
	prefix_map(map, element.row, element.col);
	find_right_bottom(map, &y, &x, &element);
	fill_square(map_char, y, x, element);
	print_square(map_char, element.row, element.col);
	free_dynamic(map, map_char, element.row);
	return ;
}

void	print_square(char **map_char, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		write(1, map_char[i], col);
		write(1, "\n", 1);
		i++;
	}
	return ;
}

void	fill_square(char **map_char, int y, int x, t_map_ele element)
{
	const int	size = element.size_sq;
	int			i;
	int			j;

	i = y - (size - 1);
	while (i <= y)
	{
		j = x - (size - 1);
		while (j <= x)
		{
			map_char[i][j] = element.for_print[SQR];
			j++;
		}
		i++;
	}
}
