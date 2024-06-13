/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:16:03 by halozdem          #+#    #+#             */
/*   Updated: 2023/12/30 13:35:35 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(int c);
int	ft_unsigned(unsigned int a);
int	ft_printf(const char *str, ...);
int	ft_hex(unsigned int hex, int control);
int	ft_ptr(unsigned long hex, int control);

#endif