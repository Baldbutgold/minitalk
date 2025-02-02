#include "minitalk.h"

void	send_signal(char *message, pid_t server_pid)
{
	int			i;
	int			current_letter;

	current_letter = 0;
	while (message[current_letter])
	{
		i = 7;
		while (i >= 0)
		{
			if ((unsigned char)(message[current_letter] >> i & 1) == 1)
				kill(server_pid, SIGUSR1);
			if ((unsigned char)(message[current_letter] >> i & 1) == 0)
				kill(server_pid, SIGUSR2);
			i--;
			usleep(50);
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
		ft_putstr_fd("require more/less args\ncommad is ./client PID MESSAGE", 1);
		return (1);
	}
	return (0);
}