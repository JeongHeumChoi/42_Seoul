/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:51:31 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/08 15:40:13 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		get_result(char *str, long long *result, int sign, char *base);
int		check_base_str(char *base);
char	*make_array_for_result(long long num, int len, char *base, int radix);
char	*ft_putnbr_base(int nbr, char *base);
int		is_base_element(char *base, char c);
void	recursion(char *target, long long num, int len, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		decimal;

	if (check_base_str(base_from) == 0 || check_base_str(base_to) == 0)
		return (0);
	decimal = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(decimal, base_to);
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long long	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	if (!get_result(str, &result, sign, base))
		return (0);
	return ((int)(result * sign));
}

int	get_result(char *str, long long *result, int sign, char *base)
{
	int	index;
	int	len;

	len = 0;
	while (base[len])
		len++;
	while (*str)
	{
		index = is_base_element(base, *str);
		if (index == -1)
			break ;
		if (*result * sign > 2147483647 || *result * sign < -2147483648)
			return (0);
		*result *= len;
		*result += index;
		str++;
	}
	return (1);
}

int	check_base_str(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (len == 0 || len == 1)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (base[i] == '+' || base[i] == '-' || \
				(base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (1);
}

char	*make_array_for_result(long long num, int len, char *base, int radix)
{
	char	*result;
	int		is_it_negative;

	result = (char *) malloc(sizeof(char) * (len + 1 + (num < 0)));
	if (result == 0)
		return (0);
	is_it_negative = 0;
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
		is_it_negative = 1;
	}
	result += is_it_negative;
	recursion(result + len - 1, num, radix, base);
	result[len] = '\0';
	result -= is_it_negative;
	return (result);
}
