/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:02:19 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/20 10:36:39 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
/*# include "libft/libft.h"*/
# include <stddef.h>

int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
char	convert_hex(unsigned int n, char x);
int		ft_puthex(unsigned int n, char x);
int		ft_putpointer(long unsigned int n, int init);
int		ft_printf(char const *format, ...);
size_t	ft_strlen(char const *str);
#endif
