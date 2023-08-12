/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 01:57:13 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 15:24:42 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	check_error(char target, int operand)
{
	if (operand != 0)
		return (0);
	else if (target == '/')
	{
		write(2, "Stop : division by zero\n", 24);
		return (1);
	}
	else if (target == '%')
	{
		write(2, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}
