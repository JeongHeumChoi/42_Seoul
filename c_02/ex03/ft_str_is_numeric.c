/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:40:39 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/30 20:56:05 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] < '0' || str[len] > '9')
			return (0);
		len++;
	}
	return (1);
}
