/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:17:29 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/27 22:20:11 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		catch_0_and_min(int n);
void	print_num(int n);

void	ft_putnbr(int nb)
{
	if (catch_0_and_min(nb))
		return ;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	print_num(nb);
	return ;
}

void	print_num(int n)
{
	char	c;

	if (n <= 0)
		return ;
	print_num(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return ;
}

int	catch_0_and_min(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}
