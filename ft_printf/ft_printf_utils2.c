/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:03:49 by halozdem          #+#    #+#             */
/*   Updated: 2023/12/30 13:34:38 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int a)
{
	unsigned int	i;

	i = 0;
	if (a <= '9')
		i += ft_putnbr(a);
	else if (a > '9')
	{
		i += ft_unsigned(a / 10);
		i += ft_unsigned(a % 10);
	}
	return (i);
}

int	ft_hex(unsigned int hex, int control)
{
	return (ft_ptr(hex, control));
}

int	ft_ptr(unsigned long hex, int control)
{
	int	i;

	i = 0;
	if (hex >= 16)
		i += ft_ptr(hex / 16, control);
	if ((hex % 16) <= 9)
		i += ft_putchar((hex % 16) + '0');
	else
	{
		if (control == 0)
			i += ft_putchar((hex % 16) + 87);
		else
			i += ft_putchar((hex % 16) + 55);
	}
	return (i);
}
