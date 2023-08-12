/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:08:11 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/02 16:06:11 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ret;
	unsigned int	cnt;

	ret = dest;
	while (*dest != '\0')
		dest++;
	cnt = 0;
	while (cnt < nb && *src)
	{
		*dest++ = *src++;
		cnt++;
	}
	*dest = '\0';
	return (ret);
}
