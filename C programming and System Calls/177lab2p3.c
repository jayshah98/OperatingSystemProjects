//Name:Jay Shah
//1-17-20
//Lab2:part3
//Creates 7 processes and only allows for creation of two child processes

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main(){
  pid_t pid;//creates 6 process ids
  printf("parent %d\n",getppid());
  for(int i = 0; i < 3; i++){//runs 7 processes
    pid = fork();
    if(pid == 0){//tests for parent
      printf("Parent:%d, Child: %d\n", getppid(), getpid());
      exit(pid);
    }
        pid = fork();
    if(pid == 0){//tests for parent

      printf("Parent:%d, Child: %d\n", getppid(), getpid());

    }

    else{
      waitpid(pid, NULL, 0);
      break;
    }
  }

  return 0;
}
