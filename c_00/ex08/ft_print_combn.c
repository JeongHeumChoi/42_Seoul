/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:49:53 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/25 14:15:14 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursion(int num, int level, int n, char *result);

void	ft_print_combn(int n)
{
	char	str[9];

	recursion(0, 1, n, str);
	return ;
}

void	recursion(int num, int level, int n, char *result)
{
	if (level == n + 1)
	{
		write(1, result, n);
		if (!(result[0] == 10 - n + '0'))
			write(1, ", ", 2);
		return ;
	}
	while (num <= 9)
	{
		result[level - 1] = num + '0';
		num += 1;
		recursion(num, level + 1, n, result);
	}
	return ;
}
