/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:58:32 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 10:17:18 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_1(char *s1, char *s2);
int	get_len_1(char **tab);

void	ft_sort_string_tab(char **tab)
{
	const int	size = get_len_1(tab);
	char		*temp;
	int			i;
	int			j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp_1(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	ft_strcmp_1(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	get_len_1(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}
