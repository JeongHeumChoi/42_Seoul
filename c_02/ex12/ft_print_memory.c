/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghch <jeonghch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:49:34 by jeonghch          #+#    #+#             */
/*   Updated: 2023/07/25 20:13:34 by jeonghch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned char *addr);
void	print_str_to_hex(unsigned char *addr, int size);
void	print_str(unsigned char *addr, int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		print_address(addr + index);
		write(1, ":", 1);
		if (index + 16 > size)
		{
			print_str_to_hex(addr + index, size - index);
			write(1, " ", 1);
			print_str(addr + index, size - index);
		}
		else
		{
			print_str_to_hex(addr + index, 16);
			write(1, " ", 1);
			print_str(addr + index, 16);
		}
		write(1, "\n", 1);
		index += 16;
	}
	return (addr);
}

void	print_address(unsigned char *addr)
{
	unsigned long long	addr_temp;
	int					four_bits;
	int					index;
	char				*hex;

	hex = "0123456789abcdef";
	four_bits = 0;
	addr_temp = (unsigned long long) addr;
	while (four_bits < 16)
	{
		index = (addr_temp >> (16 - four_bits - 1) * 4) & 0xF;
		write(1, &hex[index], 1);
		four_bits++;
	}
	return ;
}

void	print_str(unsigned char *addr, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (addr[index] >= 32 && addr[index] <= 126)
			write(1, addr + index, 1);
		else
			write(1, ".", 1);
		index++;
	}
	return ;
}

void	print_str_to_hex(unsigned char *addr, int size)
{
	int		cnt;
	char	*hex;

	hex = "0123456789abcdef";
	cnt = 0;
	while (cnt < 16)
	{
		if (cnt % 2 == 0)
			write(1, " ", 1);
		if (cnt < size)
		{
			write(1, &hex[*addr / 16], 1);
			write(1, &hex[*addr % 16], 1);
		}
		else
			write(1, "  ", 2);
		cnt++;
		addr++;
	}
	return ;
}
