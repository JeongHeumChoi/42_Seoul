/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:06:36 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/21 18:16:16 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int num);

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print(first);
			write(1, " ", 1);
			print(second);
			if (!(first == 98 && second == 99))
				write(1, ", ", 2);
			second++;
		}
		first++;
	}
	return ;
}

void	print(int num)
{
	char	first;
	char	second;

	first = num / 10 + '0';
	second = num % 10 + '0';
	write(1, &first, 1);
	write(1, &second, 1);
	return ;
}
