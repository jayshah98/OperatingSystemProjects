//Name:Jay Shah
//1-17-20
//Lab2:part2
//Creates 7 processes and only allows for creation of two child processes

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main(){
  for(int i = 0; i < 6; i++)
  {
    if(fork() !=0)//fork off child process, test if parent
    {
      waitpid(-1,NULL,0);//wait for child to finish
      break;//break to prevent creating more children
    }
    else{
      printf("Child is %d, and parent is %d \n", getpid(), getppid());
    }

  }
  return 0;
}
