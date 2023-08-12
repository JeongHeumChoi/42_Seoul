/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 02:03:20 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 03:18:59 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

void	put_nbr(long long num)
{
	char	c;

	c = num % 10 + '0';
	if (num / 10 != 0)
		put_nbr(num / 10);
	write(1, &c, 1);
	return ;
}

int	str_len(char *target)
{
	int	len;

	len = 0;
	while (target[len])
		len++;
	return (len);
}
