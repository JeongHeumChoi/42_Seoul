/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:43:02 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/30 20:57:14 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_it_alpha(char c);
int	is_it_num(char c);
int	is_it_lower(char c);
int	is_it_upper(char c);

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	is_word_finish;

	index = 0;
	is_word_finish = 1;
	while (str[index] != '\0')
	{
		if (!is_it_alpha(str[index]) && !is_it_num(str[index]))
			is_word_finish = 1;
		else
		{
			if (is_word_finish && is_it_lower(str[index]))
				str[index] -= 'a' - 'A';
			else if (!is_word_finish && is_it_upper(str[index]))
					str[index] += 'a' - 'A';
			is_word_finish = 0;
		}
		index++;
	}
	return (str);
}

int	is_it_alpha(char c)
{
	if (is_it_upper(c))
		return (1);
	else if (is_it_lower(c))
		return (1);
	return (0);
}

int	is_it_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_it_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_it_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
