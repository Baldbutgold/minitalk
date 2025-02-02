#include "minitalk.h"

void sig_handler(int signal)
{
	static int 		bit;
	static int 		i;

    if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();	
	}
}