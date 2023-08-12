/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:40:02 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/07 13:13:44 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_strs(char *str, char *delimiter);
int		is_it_delimiter(char target, char *delimiter);
int		str_len(char *str);
void	str_n_cpy(char *dest, char *src, int n);

char	**ft_split(char *str, char *charset)
{
	const int	cnt_strs = count_strs(str, charset);
	int			i;
	char		**result;
	char		*temp;

	i = 0;
	result = (char **) malloc(sizeof(char *) * (cnt_strs + 1));
	while (i < cnt_strs)
	{
		while (is_it_delimiter(*str, charset))
			str++;
		temp = str;
		while (*str && is_it_delimiter(*str, charset) == 0)
			str++;
		result[i] = (char *) malloc(sizeof(char) * (str - temp + 1));
		str_n_cpy(result[i], temp, (int)(str - temp));
		result[i][str - temp] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}

int	count_strs(char *str, char *delimiter)
{
	int	cnt;
	int	can_i_cnt;

	cnt = 0;
	can_i_cnt = 1;
	while (*str)
	{
		if (!can_i_cnt && is_it_delimiter(*str, delimiter))
			can_i_cnt = 1;
		else if (can_i_cnt && !is_it_delimiter(*str, delimiter))
		{
			can_i_cnt = 0;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

int	is_it_delimiter(char target, char *delimiter)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (delimiter[i])
	{
		len++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (target == delimiter[i])
			return (1);
		i++;
	}
	return (0);
}

void	str_n_cpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && *src)
	{
		*dest++ = *src++;
		i++;
	}
	return ;
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
