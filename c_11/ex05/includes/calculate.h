/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:27:42 by jeonghch          #+#    #+#             */
/*   Updated: 2023/08/09 12:15:46 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_H
# define CALCULATE_H

# include "operation.h"
# include "elements.h"

void	calculate(int operand1, int operand2, int op);
int		find_op(char *target);
int		ft_atoi(char *str);
int		is_space(char c);

#endif
