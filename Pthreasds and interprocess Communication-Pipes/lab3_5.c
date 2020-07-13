/*
# Name: Jay Shah
# Date:
# Title: Lab3 part 5
# Description: a C program of producer-consumer message communication using pipes. 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>
#include <string.h>

//main
int main() {
 	int fds[2];
    int count =0;
    char buff[50];
 	pipe(fds);
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
		close(fds[1]);
        count = read(fds[0],buff,1);
        while(count > 0){
            int i = 0;
            for(i = 0; i < count; ++i)
            {
                write(1,buff,1);
                count=read(fds[0],buff,1);
            }
        }
    }
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
		close(fds[0]);
        write(fds[1],"Yo\n",strlen("Yo\n"));
    }
	else {  /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
} 
