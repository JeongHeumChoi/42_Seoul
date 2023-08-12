/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:22:20 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/06 23:02:09 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_int_recursion(int i);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	while (par->str)
	{
		i = 0;
		while (par->str[i])
		{
			write(1, &(par->str[i]), 1);
			i++;
		}
		write(1, "\n", 1);
		print_int_recursion(par->size);
		write(1, "\n", 1);
		i = 0;
		while (par->copy[i])
		{
			write(1, &(par->copy[i]), 1);
			i++;
		}
		write(1, "\n", 1);
		par++;
	}
	return ;
}

void	print_int_recursion(int num)
{
	char	c;

	c = num % 10 + '0';
	if (num / 10 != 0)
		print_int_recursion(num / 10);
	write(1, &c, 1);
	return ;
}
