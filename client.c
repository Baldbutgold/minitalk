#include "minitalk.h"

char	*enc_str(char* message)
{
	int	i;
	int	j;
	int	x;
	char	*string_bits;

	j = 0;
	x = 0;
	string_bits = malloc(ft_strlen(message) + 1);
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

int	main(int av, char **ac)
{
	pid_t	server_pid;
	char	*message;
	if (av == 3)
	{
		server_pid = ft_atoi(ac[1]);
		message = ac[2];
		printf("This is server id %d\n This is the message %s\n", server_pid, message);
		printf("This is encrypted message %s\n", enc_str(message));
	}
	else
		printf("require more args");
}
