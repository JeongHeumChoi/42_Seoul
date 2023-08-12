/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:26:27 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/30 20:55:52 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_it_upper(char target);
int	is_it_lower(char target);

int	ft_str_is_alpha(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (!is_it_upper(str[len]) && !is_it_lower(str[len]))
			return (0);
		len++;
	}
	return (1);
}

int	is_it_upper(char target)
{
	if (target >= 'A' && target <= 'Z')
		return (1);
	return (0);
}

int	is_it_lower(char target)
{
	if (target >= 'a' && target <= 'z')
		return (1);
	return (0);
}
