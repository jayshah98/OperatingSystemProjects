//Name: Jay Shah
//Date: Friday Feburary 7, 2020
//Title: Lab 5
//Description: C program involving producer/consumer model using semaphores
 
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

void *Producer(void *); 
void *Consumer(void *);

sem_t *empty, *full;    
sem_t *mutex;
int temp[20],i=-1;                
#define nums 10
pthread_t thread[2];  

int main(int argc, char *argv[]) { 

  mutex=sem_open("mutex",O_CREAT,0644,1);
  empty=sem_open("empty",O_CREAT,0644,20);
  full=sem_open("full",O_CREAT,0644,0);

  printf("main initiated\n");  
  pthread_create(&thread[0], NULL, Producer, NULL);
  pthread_create(&thread[1], NULL, Consumer, NULL);
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);

  sem_unlink("mutex");
  sem_unlink("empty");
  sem_unlink("full");
  printf("main complete\n");
}


void *Producer(void *arg) {
  int prod;
  printf("Producer created\n");
  for (prod = 0; prod < nums; prod++) {
      sem_wait(empty);
      sem_wait(mutex);	
      temp[i] = 5;
      printf("%d\n",temp[i++]);
      sem_post(mutex);
      sem_post(full);
      sleep(1);
  }
}


void *Consumer(void *arg) {
  int cons;
  printf("Consumer created\n");
  for (cons = 0; cons < nums; cons++) {
      sem_wait(full);
      sem_wait(mutex);
      temp[i]=55;
      printf("%d\n",temp[i]);
      sem_post(mutex);
      sem_post(empty);
      sleep(1);
  } 
}
