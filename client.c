/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:28:09 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/03 10:28:10 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *message, pid_t pid)
{
	int	i;
	int	current_letter;

	current_letter = 0;
	while (message[current_letter])
	{
		i = 7;
		while (i >= 0)
		{
			if ((message[current_letter] >> i & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(500);
		}
		current_letter++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		if (message[0] == 0)
		{
			ft_putstr_fd("You didn't send any text, retry!", 1);
			return (0);
		}
		send_signal(message, pid);
		send_signal("\n", pid);
	}
	else
	{
		ft_putstr_fd("commad is ./client PID MESSAGE\n", 1);
		return (1);
	}
	return (0);
}
