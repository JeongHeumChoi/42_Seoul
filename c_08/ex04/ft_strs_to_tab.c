/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:51:47 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/06 23:02:24 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		str_len(char *str);
void	str_copy(char *dest, char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					i;

	ret = (struct s_stock_str *) malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		ret[i].str = av[i];
		ret[i].size = str_len(av[i]);
		ret[i].copy = (char *) malloc(sizeof(char) * (ret[i].size + 1));
		if (ret[i].copy == 0)
			return (0);
		str_copy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	ret[i].copy = 0;
	return (ret);
}

void	str_copy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
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
