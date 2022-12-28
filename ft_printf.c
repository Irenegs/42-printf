/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:30:01 by irgonzal          #+#    #+#             */
/*   Updated: 2022/12/28 17:03:30 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libftprintf.h"
/*#	include "libft.h"*/
# include <stdio.h>

static int	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		return(write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(n * -1) + 1);
	}
	if (n > 9)
		return(ft_putnbr(n / 10) + ft_putnbr(n % 10));
	c = n + '0';
	return (write(1, &c, 1));
}

static int	ft_putunsigned(unsigned int n)
{
	char c;

	if (n > 9)
		return (ft_putunsigned(n / 10) + ft_putunsigned(n % 10));
	c = n + '0';
	return (write(1, &c, 1));
}

static char convert_hex(int n, char x)
{
	if (n < 10)
		return (n + 48);
	else if (x == 'x' && n < 16)
		return (n + 87);
	else if (x == 'X' && n < 16)
		return (n + 55);
	return ('\0');
}

static int	ft_puthex(int n, char x)
{
	char	c;

	if (n < 16)
	{
		c = convert_hex(n, x);
		return (write(1, &c, 1));
	}
	return (ft_puthex(n / 16, x) + ft_puthex(n % 16, x));
}

static int	ft_putpointer(long int n)
{
	long int	pow;
	char		c;

	pow = 17592186044416;
	write(1, "0x", 2);
	while (pow != 0)
	{
		c = convert_hex(n / pow, 'x');
		write(1, &c, 1);
		n = n % pow;
		pow /= 16;
	}
	return (14);
}

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
	int				ret;
	unsigned int	a;
	char 			*str;
	ret = 2;
	if (s == 's')
	{
		str = va_arg(ptr, char *);
		ret = write(1, str, ft_strlen(str));
	}
	else if (s == 'd' || s == 'i')
	{
		a = va_arg(ptr, int);
		ret = ft_putunsigned(a);
	}
	else
	{
		a = va_arg(ptr, unsigned int);
		if (s == 'c')
			ret = write(1, &a, 1);
		if (s == 'p')
			ret = ft_putpointer(a);
		if (s == 'u')
			return (ft_putnbr((unsigned int)a));
		if (s == 'x' || s == 'X')
			ret = ft_puthex((unsigned int) a, s);
	}
	return (ret);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		printedchar;
	va_list	ptr;

	printedchar = 0;
	i = 0;
	va_start(ptr, format);//revisar num de arg con %-?
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_special(format[i + 1]) == 1)
		{
			printedchar += ft_printspecial(format[i + 1], ptr);
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			printedchar += write(1, &format[i], 1);
		}
		else
			printedchar += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (printedchar);
}

int main(void)
{
	unsigned int a = 27344712631;
	printf("ft: %d\n", ft_printf("%u\n", a));
	printf("or: %d\n", printf("%u\n",a));
	return (0);
}
