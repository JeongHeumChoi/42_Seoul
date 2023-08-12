/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:38:50 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/02 16:09:55 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c);

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

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
	return (result);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
