#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) {
  printf("0\n");
}
void signal_handler_2(int signum) {
  printf("1\n");
}

int main(void) {

  struct sigaction action;
  struct sigaction action_2;
  action.sa_handler = signal_handler;
  action_2.sa_handler = signal_handler_2;
  sigemptyset(&action.sa_mask);
  sigemptyset(&action_2.sa_mask);
  action.sa_flags = 0;
  action_2.sa_flags = 0;

  sigaction(SIGUSR1 , &action, NULL);
  sigaction(SIGUSR2 , &action_2, NULL);

  while (1) {
    // Do some work
  }

  return 0;
}
