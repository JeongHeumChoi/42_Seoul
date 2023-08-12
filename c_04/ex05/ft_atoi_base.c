/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:59:29 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/02 12:58:38 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base_str(char *base);
int	is_base_element(char *base, char c);
int	is_it_overflow(long long target);
int	get_result(char *str, long long *result, int sign, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long long	result;

	if (!check_base_str(base))
		return (0);
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
		if (is_it_overflow(*result * sign))
			return (0);
		*result *= len;
		*result += index;
		str++;
	}
	return (1);
}

int	is_base_element(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
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

int	is_it_overflow(long long target)
{
	if (target > 2147483647 || target < -2147483648)
		return (1);
	return (0);
}
