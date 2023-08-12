/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:35:24 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 11:36:04 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dp.h"
#include "solve.h"

int	get_min(int lb, int lt, int rt);

void	prefix_map(int **map, int row, int col)
{
	int	i;
	int	j;

	i = 1;
	while (i < row)
	{
		j = 1;
		while (j < col)
		{
			if (map[i][j] != 0)
				map[i][j] = get_min(map[i][j - 1], map[i - 1][j - 1], \
								map[i - 1][j]) + 1;
			j++;
		}
		i++;
	}
}

void	find_right_bottom(int **map, int *y, int *x, t_map_ele *element)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (i < element->row)
	{
		j = 0;
		while (j < element->col)
		{
			if (max < map[i][j])
			{
				max = map[i][j];
				*y = i;
				*x = j;
			}
			j++;
		}
		i++;
	}
	element->size_sq = max;
}

int	get_min(int lb, int lt, int rt)
{
	int	min;

	min = lb;
	if (lt < min)
		min = lt;
	if (rt < min)
		min = rt;
	return (min);
}
