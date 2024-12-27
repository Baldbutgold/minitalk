#include "minitalk.h"

char	*msg_transform(char *message)
{
	int	i;
	int	j;
	unsigned char	bit;
	char	*transformed_message;

	transformed_message = malloc((ft_strlen(message) * 8) + 1);
	while (message[i++])
	{
		j = 8;
		while (j--)
			transformed_message[i + j] = (octet >> i & 1) + '0';
	}
	transformed_message[i] = '\0';
	return (transformed_message);
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
	}
	else
		printf("require more args");
}
