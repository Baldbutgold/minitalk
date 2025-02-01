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
}

int	main(void)
{
	struct sigaction	signal_received;
	pid_t				server_pid;

	sigemptyset(&signal_received.sa_mask);
	printf("%d\n", (int)getpid());	
	signal_received.sa_handler = sig_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);

	while (1)
		sleep(100);
}
