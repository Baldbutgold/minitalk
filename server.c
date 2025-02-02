#include "minitalk.h"

static void sig_handler(int signum)
{
    static unsigned char    c = 0;
    static int             bits = 0;

    if (signum == SIGUSR1)
        c = (c << 1) | 1;
    else if (signum == SIGUSR2)
        c = (c << 1) | 0;
    
    bits++;
    if (bits == 8)
    {
        ft_putchar_fd(c, 1);
        bits = 0;
        c = 0;
    }
}

int main(void)
{
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);

    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);

    while (1)
        sleep(100);
    return (0);
}
