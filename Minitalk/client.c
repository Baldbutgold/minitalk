#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

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
	static int	count = 0;

	i = 0;
	while (enc_message[i])
	{
//		printf("in loop at %d message : %c\n", i, enc_message[i]);
		if (enc_message[i] == '1')
		{
			printf("sending 1\n");
			kill(server_pid, SIGUSR1);
			count += 1;
		}
		else if (enc_message[i] == '0')
		{
			printf("sending 0\n");
			kill(server_pid, SIGUSR2);
			count += 1;
		}
		i++;
		usleep(50);
	}
	printf("this is count %d\n", count);
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
