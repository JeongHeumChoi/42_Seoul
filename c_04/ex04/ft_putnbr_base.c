/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:19:07 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/07 23:34:07 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	print_recursion(long long nbr, int len, char *base);
int		check_base_str(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	const int	len = ft_strlen(base);
	long long	num;

	if (!check_base_str(base))
		return ;
	if (nbr < 0)
	{
		num = (long long)nbr * -1;
		write(1, "-", 1);
	}
	else
		num = nbr;
	if (num)
		print_recursion(num, len, base);
	else
		write(1, &base[0], 1);
	return ;
}

void	print_recursion(long long nbr, int len, char *base)
{
	if (nbr <= 0)
		return ;
	print_recursion(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
	return ;
}

int	check_base_str(char *base)
{
	int			i;
	int			j;
	const int	len = ft_strlen(base);

	if (len == 0 || len == 1)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int main(void) {

	ft_putnbr_base(56895, "456789");


	return 0;
}
