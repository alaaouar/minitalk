/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:59:42 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/19 19:46:09 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	c;
	static int				i;

	if (signal == SIGUSR1)
		c |= 1 << i;
	else if (signal == SIGUSR2)
		c |= 0 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			c = 0;
			i = 0;
		}
		else
		{
			ft_putchar_fd(c, 1);
			c = 0;
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	(void)**argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	ft_putstr_fd("server running PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}
