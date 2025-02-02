#include "minitalk.h"
#include <signal.h>

void sig_handler(int signum)
{
    if (signum == SIGUSR1)
        write(1, "1\n", 2);
    if (signum == SIGUSR1)
        write(1, "0\n", 2);
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal_received.sa_handler = sig_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);

	while (1)
		sleep(1000);	
}
