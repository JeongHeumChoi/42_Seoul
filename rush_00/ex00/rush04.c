/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:10:07 by sehwjang          #+#    #+#             */
/*   Updated: 2023/07/22 20:28:46 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char *line_elements)
{
	int		x_i;

	x_i = 0;
	while (x_i < x)
	{
		if (x_i == 0)
			ft_putchar(line_elements[0]);
		else if (x_i == x - 1)
			ft_putchar(line_elements[2]);
		else
			ft_putchar(line_elements[1]);
		x_i++;
	}
}

void	rush(int x, int y)
{
	char	*elements[3];
	int		y_i;

	if (!(x * y))
		return ;
	elements[0] = "ABC";
	elements[1] = "B B";
	elements[2] = "CBA";
	y_i = 0;
	while (y_i < y)
	{
		if (y_i == 0)
			print_line(x, elements[0]);
		else if (y_i == y - 1)
			print_line(x, elements[2]);
		else
			print_line(x, elements[1]);
		ft_putchar('\n');
		y_i++;
	}
}
