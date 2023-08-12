/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:12 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/03 16:21:59 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	index;

	i = argc - 1;
	while (i > 0)
	{
		index = 0;
		while (argv[i][index] != '\0')
		{
			write(1, &argv[i][index], 1);
			index++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
