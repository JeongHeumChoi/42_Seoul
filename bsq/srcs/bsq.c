/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:17:23 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 22:48:25 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		solve(argv[i]);
		if (i != argc - 1)
			write(1, "\n", 1);
	}
	return (0);
}
