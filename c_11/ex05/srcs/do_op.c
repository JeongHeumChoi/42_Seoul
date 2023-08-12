/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:39:09 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 14:27:15 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char *argv[])
{
	int	operand1;
	int	operand2;
	int	op;

	if (argc != 4)
		return (0);
	op = find_op(argv[2]);
	if (op == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	operand1 = ft_atoi(argv[1]);
	operand2 = ft_atoi(argv[3]);
	if (check_error(argv[2][0], operand2))
		return (0);
	calculate(operand1, operand2, op);
	write(1, "\n", 1);
	return (0);
}
