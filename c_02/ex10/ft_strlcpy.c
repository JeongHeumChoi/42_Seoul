/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:41:51 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/30 20:57:22 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	index;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	index = 0;
	while (index < size - 1 && index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (len);
}
