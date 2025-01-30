#include "minitalk.h"

void	sig_handler(int signum)
{
	static int	counter = 0;

	if (signum == SIGUSR1)
	{
		printf("1\n");
		counter += 1;
	}
	else if (signum == SIGUSR2)
	{
		printf("0\n");
		counter += 1;
	}
	//printf("%d\n", counter);
}

int	main()
{
	struct sigaction	signal_recieved;
	pid_t	server_pid;

	printf("%d\n", (int)getpid());	
	signal_recieved.sa_handler = sig_handler;
	signal_recieved.sa_flags = 0;
	sigaction(SIGUSR1, &signal_recieved, NULL);
	sigaction(SIGUSR2, &signal_recieved, NULL);

	while (1)
		sleep(100);
}
