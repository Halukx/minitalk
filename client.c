/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:24:38 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/13 13:59:00 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

static pid_t	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

static int	convert_pid(char *pid)
{
	pid_t		res;
	size_t		i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!('0' >= pid[i] && pid[i] <= '9'))
		{
			ft_printf("PID sadece rakamlardan olusmalidir.");
			exit(1);
		}
		i++;
	}
	res = 0;
	res = ft_atoi(pid);
	return (res);
}

static void	sending_signal(char letter, pid_t *pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if ((letter & (1 << i)) != 0)
			kill(*pid, SIGUSR1);
		else
			kill(*pid, SIGUSR2);
		usleep(125);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc == 3)
	{
		i = 0;
		pid = convert_pid(argv[1]);
		if (kill(pid, 0) != 0)
		{
			ft_printf("Yanlis PID girdiniz!");
			exit(1);
		}
		while (argv[2][i] != '\0')
			sending_signal(argv[2][i++], &pid);
		sending_signal('\n', &pid);
		return (0);
	}
	else
		ft_printf("Hatali arguman sayisi girdiniz!");
}
