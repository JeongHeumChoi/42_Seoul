/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:29:25 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/07 13:09:13 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	if (min >= max || range == 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (*range == 0)
		return (-1);
	index = 0;
	while (index + min < max)
	{
		(*range)[index] = index + min;
		index++;
	}
	return (max - min);
}
