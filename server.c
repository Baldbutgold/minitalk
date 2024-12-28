#include "minitalk.h"

void	sigusr1_handler(int signum)
{
	printf("Got Sigusr1 : 1\n");
}

void	sigusr2_handler(int signum)
{
	printf("Got Sigusr2 : 0\n");
}

int	main()
{
	pid_t	server_pid;

	server_pid = getpid();
	printf("%d\n", server_pid);

	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);

	while (1)
		sleep(100);
}
