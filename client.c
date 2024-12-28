#include "minitalk.h"

char	*enc_str(char *message)
{
	int		i;
	int		j;
	int		x;
	char	*string_bits;

	j = 0;
	x = 0;
	string_bits = malloc(ft_strlen(message) * 8 + 1);
	if (!string_bits)
		return (NULL);
	while (message[x])
	{
		i = 8;
		while (i--)
			string_bits[j++] = (message[x] >> i & 1) + '0';
		x++;
	}
	string_bits[j] = 0;
	return (string_bits);
}

void	send_signal(char *enc_message, pid_t server_pid)
{
	int	i;

	i = 0;
	while (enc_message[i])
	{
//		printf("in loop at %d message : %c\n", i, enc_message[i]);
		if (enc_message[i] == '1')
		{
			printf("sending 1\n");
			kill(server_pid, SIGUSR1);
		}
		else if (enc_message[i] == '0')
		{
			printf("sending 0\n");
			kill(server_pid, SIGUSR2);
		}
		i++;
	}
}

int	main(int av, char **ac)
{
	pid_t	pid;
	char	*message;

	if (av == 3)
	{
		pid = ft_atoi(ac[1]);
		message = ac[2];
		send_signal(enc_str(message), pid);
	}
	else
		printf("require more args");
}
