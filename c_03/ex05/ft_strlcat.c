/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:36:57 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/02 23:05:52 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen_2(char *target);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	const unsigned int	dest_len = ft_strlen_2(dest);
	const unsigned int	src_len = ft_strlen_2(src);
	unsigned int		i;

	i = 0;
	if (size < dest_len + 1)
		return (size + src_len);
	else if (size > dest_len + 1)
	{
		while (src[i] && dest_len + i + 1 < size)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

unsigned int	ft_strlen_2(char *target)
{
	unsigned int	len;

	len = 0;
	while (target[len])
		len++;
	return (len);
}
