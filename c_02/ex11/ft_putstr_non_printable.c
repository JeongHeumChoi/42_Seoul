/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:18:37 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/27 18:34:06 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				len;
	unsigned char	temp;
	const char		*hex = "0123456789abcdef";

	len = 0;
	while (str[len] != '\0')
	{
		temp = str[len];
		if (!(temp < 32 || temp > 126))
			write(1, &temp, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[temp / 16], 1);
			write(1, &hex[temp % 16], 1);
		}
		len++;
	}
	return ;
}
