#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) 
{
  printf("Received SIGUSR1!\n", signum);
  exit(0);
}

int main() 
{
	printf("%d\n", getpid());
  
  signal(SIGUSR1, signal_handler);

  while (1) {
    // Do some work here...
    pause();
  }

  return 0;
}
