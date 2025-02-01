#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"

void    sig_handler(int signum);
void    handle_signals(void);  // Add prototype

#endif
