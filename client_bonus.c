/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:19:56 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/16 20:18:17 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
	}
}

int	argument_checker(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr_fd("Error: Wrong PID\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argument_checker(argc, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
