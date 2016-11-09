#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void sighandler(int signal){
  if (signal == SIGUSR1) {
    printf("parent id: %d\n",getppid());
  }

  if (signal == SIGINT) {
    printf("fatal: program exited due to SIGINT\n");
    exit(2);
  }
 
}

int main(){
  
  while (1){

    printf("pid: %d\n",getpid());
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    sleep(1);
  }

  return 0;
}
