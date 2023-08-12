/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:11:13 by sehwjang          #+#    #+#             */
/*   Updated: 2023/07/23 15:47:27 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void					rush(int x, int y);
int						ft_atoi(char *str);
int						is_it_overflow(char *num);
int						ft_strlen(char *target);
char					*get_only_num(char *input);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(2, "ERROR : Not right arguments!\n", 29);
		return (-1);
	}
	argv[1] = get_only_num(argv[1]);
	argv[2] = get_only_num(argv[2]);
	if (is_it_overflow(argv[1]) || is_it_overflow(argv[2]))
	{
		write(2, "ERROR : Overflow occured!\n", 26);
		return (-1);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x == -1 || y == -1)
	{
		write(2, "ERROR : Invalid input!\n", 23);
		return (-1);
	}
	rush(x, y);
	return (0);
}

int	ft_atoi(char *str)
{
	int		result;

	result = 0;
	if (*str == '\0')
		return (-1);
	while (*str != '\0' && !(*str < '0' || *str > '9'))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

int	is_it_overflow(char *num)
{
	char	*int_max;
	int		num_len;
	int		max_len;

	int_max = "2147483647";
	num_len = ft_strlen(num);
	max_len = ft_strlen(int_max);
	if (max_len < num_len)
		return (1);
	else if (max_len > num_len)
		return (0);
	while (*num != '\0')
	{
		if (*num > *int_max)
			return (1);
		else if (*num < *int_max)
			return (0);
		num++;
		int_max++;
	}
	return (0);
}

int	ft_strlen(char *target)
{
	int	index;

	index = 0;
	while (target[index] != '\0')
		index++;
	return (index);
}

char	*get_only_num(char *input)
{
	char	*ptr;
	char	*result;

	ptr = input;
	while (*ptr < 33 || *ptr == 127)
	{
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	if (*ptr == '+')
		ptr++;
	result = ptr;
	while (*ptr != '\0' && !(*ptr < '0' || *ptr > '9'))
		ptr++;
	*ptr = '\0';
	return (result);
}
