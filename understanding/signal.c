#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) 
{
  printf("Received SIGINT!\n", signum);
  exit(0);
}

int main() 
{
  // Set the signal handler for the SIGINT and SIGTERM signals
  // to the signal_handler function
  
  signal(SIGINT, signal_handler);

  while (1) {
    // Do some work here...
	printf("%d", getpid());
    pause();
  }

  return 0;
}
