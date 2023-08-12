/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:28:00 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/10 15:43:51 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	asc;
	int	desc;
	int	ret;
	int	i;

	i = 0;
	asc = 1;
	desc = 1;
	while (i < length - 1)
	{
		ret = f(tab[i], tab[i + 1]);
		if (ret < 0)
			desc = 0;
		if (ret > 0)
			asc = 0;
		i++;
	}
	return (asc | desc);
}
