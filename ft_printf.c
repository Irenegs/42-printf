/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:30:01 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/20 10:47:01 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libftprintf.h"

static int	is_special(char c)
{
	char	*sp_char;

	sp_char = "cspdiuxX";
	while (*sp_char != '\0')
	{
		if (*sp_char == c)
			return (1);
		sp_char++;
	}
	return (0);
}

static int	ft_printspecial(char const s, va_list ptr)
{
	long unsigned int	a;
	char				*str;

	if (s == 's')
	{
		str = va_arg(ptr, char *);
		if (!str)
			return (write(1, "(null)", 6));
		return (write(1, str, ft_strlen(str)));
	}
	else if (s == 'd' || s == 'i' || s == 'c' || s == 'x' || s == 'X')
	{
		a = va_arg(ptr, int);
		if (s == 'c')
			return (write(1, &a, 1));
		if (s == 'x' || s == 'X')
			return (ft_puthex(a, s));
		return (ft_putnbr(a));
	}
	a = va_arg(ptr, long unsigned int);
	if (s == 'p')
		return (ft_putpointer(a, 1) + 2);
	return (ft_putunsigned(a));
}

static int	percent_found(char const *format, int i, va_list ptr)
{
	if (is_special(format[i + 1]) == 1)
		return (ft_printspecial(format[i + 1], ptr));
	if (format[i + 1] == '%')
		return (write(1, &format[i], 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		printedchar;
	va_list	ptr;

	printedchar = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printedchar += percent_found(format, i, ptr);
			i++;
		}
		else
			printedchar += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (printedchar);
}
