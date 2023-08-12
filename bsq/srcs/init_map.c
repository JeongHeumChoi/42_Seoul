/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:42:27 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 11:36:42 by sooyouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_map.h"

int	get_element(char *file_name, t_map_ele *target)
{
	const int	fd = fopen_read(file_name);
	char		temp;

	target->row = get_row(fd, &temp);
	target->for_print[0] = temp;
	read(fd, target->for_print + 1, 2);
	read(fd, &temp, 1);
	if (temp != '\n')
		return (0);
	target->col = 0;
	read(fd, &temp, 1);
	while (temp != '\n')
	{
		read(fd, &temp, 1);
		target->col++;
	}
	close(fd);
	return (1);
}

int	get_row(int fd, char *temp)
{
	int	row;

	read(fd, temp, 1);
	while ((*temp >= 9 && *temp <= 13) || *temp == 32)
		read(fd, temp, 1);
	row = 0;
	while (*temp >= '0' && *temp <= '9')
	{
		row = row * 10 + (*temp - '0');
		read(fd, temp, 1);
	}
	return (row);
}

void	init_map(char *file_name, int **map, char **map_char, t_map_ele element)
{
	const int	fd = fopen_read(file_name);
	int			i;
	char		*temp;

	temp = (char *) malloc(sizeof(char) * element.col);
	read(fd, temp, 1);
	while (temp[0] != '\n')
		read(fd, temp, 1);
	i = 0;
	while (i < element.row)
	{
		read(fd, temp, element.col);
		convert_c_to_i(map[i], temp, element.col, element.for_print);
		copy_f_to_c(map_char[i], temp, element.col);
		read(fd, temp, 1);
		i++;
	}
	free(temp);
	close(fd);
}

void	convert_c_to_i(int *dest_arr, char *src_arr, int col, char *for_print)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (src_arr[i] == for_print[EMPTY])
			dest_arr[i] = 1;
		else if (src_arr[i] == for_print[OBST])
			dest_arr[i] = 0;
		i++;
	}
	return ;
}

void	copy_f_to_c(char *dest_arr, char *src_arr, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		dest_arr[i] = src_arr[i];
		i++;
	}
	return ;
}
