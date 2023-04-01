/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:36:58 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/19 10:24:34 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libftprintf.h"

int	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(n * -1) + 1);
	}
	if (n > 9)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	c = n + '0';
	return (write(1, &c, 1));
}

int	ft_putunsigned(unsigned int n)
{
	char	c;

	if (n > 9)
		return (ft_putunsigned(n / 10) + ft_putunsigned(n % 10));
	c = n + '0';
	return (write(1, &c, 1));
}

char	convert_hex(unsigned int n, char x)
{
	if (n < 10)
		return (n + 48);
	else if (x == 'x' && n < 16)
		return (n + 87);
	else if (x == 'X' && n < 16)
		return (n + 55);
	return ('\0');
}

int	ft_puthex(unsigned int n, char x)
{
	char	c;

	if (n < 16)
	{
		c = convert_hex(n, x);
		return (write(1, &c, 1));
	}
	return (ft_puthex(n / 16, x) + ft_puthex(n % 16, x));
}

int	ft_putpointer(long unsigned int n, int init)
{
	char	c;
	int		res;

	if (init == 1)
		write(1, "0x", 2);
	if (n < 16)
	{
		c = convert_hex(n, 'x');
		return (write(1, &c, 1));
	}
	res = ft_putpointer(n / 16, 0) + ft_putpointer(n % 16, 0);
	return (res);
}
