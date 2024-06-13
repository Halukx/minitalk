/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:58:07 by halozdem          #+#    #+#             */
/*   Updated: 2023/12/30 13:34:16 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		i = ft_putstr("(null)");
		return (i);
	}
	while (c[i])
		i += ft_putchar(c[i]);
	return (i);
}

int	ft_putnbr(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
		i += ft_putstr("-2147483648");
	else if (c < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(c * (-1));
	}
	else if (c > 9)
	{
		i += ft_putnbr(c / 10);
		i += ft_putnbr(c % 10);
	}
	else if (c <= 9)
	{
		i += ft_putchar(c + 48);
	}
	return (i);
}
