/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:25:41 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/06 16:38:26 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	index;

	if (min >= max)
		return (0);
	ret = (int *) malloc(sizeof(int) * (max - min));
	if (ret == 0)
		return (0);
	index = 0;
	while (index + min < max)
	{
		ret[index] = index + min;
		index++;
	}
	return (ret);
}
