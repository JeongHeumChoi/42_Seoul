/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:50:54 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/07 13:09:27 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_result_len(int size, char **strs, char *sep);
int	str_cat(char *str_main, char *src, int idx);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	const int	len = get_result_len(size, strs, sep);
	char		*result;
	int			i;
	int			index;

	result = (char *) malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	index = 0;
	while (i < size)
	{
		index = str_cat(result, *(strs + i), index);
		i++;
		if (i != size)
			index = str_cat(result, sep, index);
	}
	result[index] = '\0';
	return (result);
}

int	get_result_len(int size, char **strs, char *sep)
{
	int	ret_len;
	int	str_len;
	int	sep_len;
	int	i;

	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	i = 0;
	ret_len = 0;
	while (i < size)
	{
		str_len = 0;
		while (strs[i][str_len] != '\0')
			str_len++;
		ret_len += str_len;
		if (i != size - 1)
			ret_len += sep_len;
		i++;
	}
	return (ret_len);
}

int	str_cat(char *str_main, char *src, int idx)
{
	while (*src)
	{
		str_main[idx] = *src;
		idx++;
		src++;
	}
	return (idx);
}
