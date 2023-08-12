/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:56:20 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/03 15:57:37 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_it_prime(int nb);

int	ft_find_next_prime(int nb)
{
	while (!is_it_prime(nb))
		nb++;
	return (nb);
}

int	is_it_prime(int nb)
{
	long long	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
