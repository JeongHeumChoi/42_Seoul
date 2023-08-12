/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:27:11 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 22:34:11 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
# define ALLOCATION_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		fopen_read(char *file_name);
int		**alloc_map(int row, int col);
char	**alloc_map_char(int row, int col);
void	free_dynamic(int **map, char **map_char, int row);

#endif
