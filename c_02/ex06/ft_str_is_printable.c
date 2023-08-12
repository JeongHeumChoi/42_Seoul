/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:25:00 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/30 20:56:36 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] < 32 || str[len] > 126)
			return (0);
		len++;
	}
	return (1);
}
