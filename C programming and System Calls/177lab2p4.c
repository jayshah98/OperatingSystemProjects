//Name:Jay Shah
//1-17-20
//Lab2:part4
//Uses threads to observed child and parent proceses




#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void *childRoutine(void *arg);

int main(int argc, char *argv[]){

	int i;
	pthread_t threadId;
	int arg = atoi(argv[i]);
	pthread_create(&threadId,NULL,childRoutine,&arg);//creates new thread

	for(i = 0; i<100; i++)
	{
		printf("\t \t \tParent Thread %d\n", i);
		usleep(arg);
	}

	pthread_join(threadId,NULL);
	return 0;

}

void *childRoutine(void *arg){

	int i, *arug=arg;
	for(i = 0; i<100; i++)
	{
		printf("Child Thread %d\n",i);
		usleep(*arug);
	}

}
