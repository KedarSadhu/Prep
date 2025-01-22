#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>	//for sleep

int g_iNo;
sem_t _lock;

void * t_handler(void * vargs)
{
	int i;
	int * pNum = (int *)vargs;

	sem_wait(&_lock);
	sleep(2);
	for(i = 0;i < 10;i++)
	{	
		g_iNo++;
		(*pNum)++;
		printf("pthread_id = %ld \t g_iNo = %d \t pNum = %d\n",pthread_self(),g_iNo,(*pNum));
	}
	sem_post(&_lock);
}

int main()
{
	int i;
	pthread_t tid[2];
	int Num = 100;

	/*
       int sem_init(sem_t *sem, int pshared, unsigned int value);
	
		sem 	: initializes the unnamed semaphore at the address pointed to by sem
		
		pshared : The pshared argument indicates whether this semaphore is to be
       			  shared between the threads or between processes.
       			  pshared = 0 --> between the threads
       			  pshared = Nonzero --> between the processess

       	value 	: The value argument specifies the initial value for the semaphore.

	*/
	sem_init(&_lock,0,1);

	for(i = 0; i < 2;i++)
	{
		pthread_create(&tid[i],NULL,t_handler,(void *)&Num);
		
	}

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	
	sem_destroy(&_lock);

	printf("\nIn Main thread \n");
	exit(0);
}