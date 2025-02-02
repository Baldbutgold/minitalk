#include "minitalk.h"

// char	*enc_str(char *message)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	char	*string_bits;

// 	j = 0;
// 	x = 0;
// 	string_bits = malloc(ft_strlen(message) * 8 + 1);
// 	if (!string_bits)
// 		return (NULL);
// 	while (message[x])
// 	{
// 		i = 8;
// 		while (i--)
// 			string_bits[j++] = (message[x] >> i & 1) + '0';
// 		x++;
// 	}
// 	string_bits[j] = 0;
// 	return (string_bits);
// }

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
			printf("I is : %d\n", i);
			if (((unsigned char)(message[current_letter] >> (7 - i)) & 1) == 1)
				kill(server_pid, SIGUSR1);
			if (((unsigned char)(message[current_letter] >> (7 - i)) & 1) == 0)
				kill(server_pid, SIGUSR2);
			i--;
			usleep(50);
		}
		current_letter++;
	}
	printf("\n current letter : %d\n", current_letter);
}

int	main(int av, char **ac)
{
	pid_t	pid;
	char	*message;

	if (av == 3)
	{
		pid = ft_atoi(ac[1]);
		if (!pid)
		{
			ft_putstr_fd("ERROR, Wrong value", 1);
			return (0);
		}
		message = ac[2];
		if (message[0] == 0)
		{
			ft_putstr_fd("You didn't send any text, retry!", 1);
			return (0);
		}
		send_signal(message, pid);
	}
	else
		ft_putstr_fd("require more/less args\n commad is ./client PID MESSAGE", 1);
	return (0);
}