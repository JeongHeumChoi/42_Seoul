/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:22:35 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/03 16:56:28 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	bubble_sort(char *argv[], int size);
void	print_prams(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	bubble_sort(argv + 1, argc - 1);
	print_prams(argc - 1, argv + 1);
	return (0);
}

void	bubble_sort(char *argv[], int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	print_prams(int argc, char *argv[])
{
	int	i;
	int	index;

	i = 0;
	while (i < argc)
	{
		index = 0;
		while (argv[i][index] != '\0')
		{
			write(1, &argv[i][index], 1);
			index++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

int	ft_strcmp(char *s1, char *s2)
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
