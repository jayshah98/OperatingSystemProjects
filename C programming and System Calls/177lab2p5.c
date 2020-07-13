//Name:Jay Shah
//1-17-20
//Lab2:part5
//Descrition:Program allows for child to execute "ls" command and parent waits for child




#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */

pid_t wait(int *status);
void fun(pid_t pid){
  if(pid == 0)
  {
    execlp("/bin/ls", "ls", NULL);
  }
  else
  {
    wait(NULL);
    printf("Child Complete");
    exit(0);
  }
}

void child(pid_t pid) {
  printf(" CHILD I'm alive\n");
  fun(pid);
  exit(EXIT_SUCCESS);
}

void parent(pid_t pid) {
  printf("PARENT Spawned a child\n");
  fun(pid);
  printf("PARENT Goodbye.\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  pid_t pid;
  int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
  printf("\n Before forking.\n");
  pid = fork();

  switch (pid){
    case -1:
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
    case 0:
      // Child process. prints ls instead of running child
      child(pid);
    default:
      // Parent process
      parent(pid);
    }
return 0;
}
