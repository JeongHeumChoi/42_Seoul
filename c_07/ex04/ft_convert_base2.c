/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:26:01 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/08 15:40:32 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
void	get_length(long long num, int radix, int *cnt);
char	*make_array_for_result(long long num, int len, char *base, int radix);

char	*ft_putnbr_base(int nbr, char *base)
{
	const int	len_radix = ft_strlen(base);
	long long	num;
	char		*result;
	int			sign;
	int			len_str;

	sign = 1;
	if (nbr < 0)
	{
		num = (long long) nbr * -1;
		sign = -1;
	}
	else
		num = nbr;
	len_str = 0;
	get_length(num, len_radix, &len_str);
	result = make_array_for_result(sign * num, len_str, base, len_radix);
	if (result == 0)
		return (0);
	return (result);
}

void	recursion(char *target, long long num, int radix, char *base)
{
	if (num / radix != 0)
		recursion(target - 1, num / radix, radix, base);
	*target = base[num % radix];
	return ;
}

void	get_length(long long num, int radix, int *cnt)
{
	if (num / radix != 0)
		get_length(num / radix, radix, cnt);
	(*cnt)++;
	return ;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
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
