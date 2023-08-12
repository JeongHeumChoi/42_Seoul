/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:26:25 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 10:34:56 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

int	fopen_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, S_IRUSR);
	if (fd < 0)
	{
		write(2, "Error : fopen_read()\n", 21);
		return (-1);
	}
	return (fd);
}

int	**alloc_map(int row, int col)
{
	int	**map;
	int	i;

	map = (int **) malloc(sizeof(int *) * row);
	if (map == 0)
		return (0);
	i = 0;
	while (i < row)
	{
		map[i] = (int *) malloc(sizeof(int *) * col);
		if (map[i] == 0)
			return (0);
		i++;
	}
	return (map);
}

char	**alloc_map_char(int row, int col)
{
	char	**map_char;
	int		i;

	map_char = (char **) malloc(sizeof(char *) * row);
	if (map_char == 0)
		return (0);
	i = 0;
	while (i < row)
	{
		map_char[i] = (char *) malloc(sizeof(char *) * col);
		if (map_char[i] == 0)
			return (0);
		i++;
	}
	return (map_char);
}

void	free_dynamic(int **map, char **map_char, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		free(map_char[i]);
		i++;
	}
	free(map);
	free(map_char);
}
