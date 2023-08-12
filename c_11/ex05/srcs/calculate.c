/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:20:28 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 21:10:41 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"

void	calculate(int operand1, int operand2, int op)
{
	long long	result;
	int			(*f[5])(int, int);

	f[0] = plus;
	f[1] = minus;
	f[2] = div;
	f[3] = mult;
	f[4] = modulo;
	result = f[op](operand1, operand2);
	if (result < 0)
	{
		write(1, "-", 1);
		result *= -1;
	}
	put_nbr(result);
	return ;
}

int	find_op(char *target)
{
	const char	*op = "+-/*%";
	int			i;

	if (str_len(target) != 1)
		return (-1);
	i = 0;
	while (i < 5)
	{
		if (op[i] == target[0])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int			sign;
	long long	result;

	while (is_space(*str))
			str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= sign;
	return ((int) result);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
