#include "minitalk.h"

char	*msg_transform(char *message)
{
	int	i;
	int	j;
	char	*transformed_message;

	i = 0;
	transformed_message = malloc((ft_strlen(message) * 8) + 1);
	if (!transformed_message)
		return (NULL);
	printf("malloced %ld\n", ft_strlen(message) * 8 + 1);
	transformed_message[0] = 0;
	while (message[i] != '\0')
	{
		printf("this is i : %d\n", i);
		j = 8;
		while (j--)
		{
			printf("this is j : %d and this is the char %c\n and this is bit? %c\n", j, message[i], message[i] >> i + j & 1 + '0');
			transformed_message[i + j] = (message[i] >> i + j& 1) + '0';
		}
		i++;
	}
	printf("null terminated at %d\n", i * 8 + 1);
	transformed_message[(i * 8) + 1] = 0;
	printf("this is the bitted message %s\n", transformed_message);
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
		msg_transform(message);
	}
	else
		printf("require more args");
}
