/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:56:53 by halozdem          #+#    #+#             */
/*   Updated: 2023/12/30 13:40:10 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	format(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if ((c == 'i') || (c == 'd'))
		i += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		i += ft_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		i += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		i += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_ptr(va_arg(arg, unsigned long), 0);
	}
	else if (c == '%')
		i += ft_putchar('%');
	else
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
				i++;
			count += format(str[i], arg);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
