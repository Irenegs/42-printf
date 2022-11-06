/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:30:01 by irgonzal          #+#    #+#             */
/*   Updated: 2022/10/19 20:38:33 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libftprintf.h"
#	include "libft.h"

static int	ft_printspecial(char const *s, void a)
{
	if (*(s + 1) == '%')
		return (write(1, "%", 1));
	if (*(s + 1) == 'c')
		return (write(1, a, 1));
	if (*(s + 1) == 's')
		return (write(1, (char *)a, ft_strlen((char *)a)));
	if (*(s + 1) == 'p')
		return (ft_write_pointer(a, 1));
	if (*(s + 1) == 'd' || *(s + 1) == 'i')		
		return(ft_write_int((int)a, 1));//TODO revisar * en esta linea y en -2 y -4
	if (*(s + 1) == 'u')
		return (ft_write_u((unsined int)a, 1));
	if (*(s + 1) == 'x' || *(s + 1) == 'X')
		return (ft_puthex((unsigned int)a, *(s + 1), 1));
	return (-1);
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
		if (format[i] == '%')
		{
			printedchar += ft_printspecial(format[i], va_arg(ptr, void));
			i++;
		}
		else
			printedchar += write(1, format[i], 1);
		i++;
		printedchar++;
	}
	va_end(ptr);
	return (printedchar);
}
