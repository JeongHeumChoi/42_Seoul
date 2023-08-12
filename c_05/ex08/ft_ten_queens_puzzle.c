/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:28:42 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/02 23:22:11 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10
#define COL 10
#define CROSS 19
#define NOTHING -1

void	search(int column[], int cross[][CROSS], int *cnt, int selected);
void	print_queens(int column[]);
void	init(int target[], int size);

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	column[COL];
	int	cross[CROSS][CROSS];

	init(column, COL);
	init(cross[0], CROSS);
	init(cross[1], CROSS);
	search(column, cross, &cnt, 0);
	return (cnt);
}

void	search(int column[], int cross[][CROSS], int *cnt, int selected)
{
	int	i;

	if (selected == SIZE)
	{
		print_queens(column);
		(*cnt)++;
	}
	else
	{
		i = -1;
		while (++i < SIZE)
		{
			if (column[i] != NOTHING || cross[0][i + selected] != NOTHING || \
					cross[1][i - selected + SIZE - 1] != NOTHING)
				continue ;
			column[i] = selected;
			cross[0][i + selected] = i;
			cross[1][i - selected + SIZE - 1] = i;
			search(column, cross, cnt, selected + 1);
			column[i] = NOTHING;
			cross[0][i + selected] = NOTHING;
			cross[1][i - selected + SIZE - 1] = NOTHING;
		}
	}
}

void	print_queens(int column[])
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (column[j] == i)
			{
				temp = j + '0';
				write(1, &temp, 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return ;
}

void	init(int target[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		target[i] = NOTHING;
		i++;
	}
	return ;
}
