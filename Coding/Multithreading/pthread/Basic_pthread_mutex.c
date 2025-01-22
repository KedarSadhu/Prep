#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>	//for sleep

int g_iNo;
pthread_mutex_t _lock;

void * t_handler(void * vargs)
{
	int i;
	int * pNum = (int *)vargs;

	pthread_mutex_lock(&_lock);

	sleep(2);
	for(i = 0;i < 10;i++)
	{	
		g_iNo++;
		(*pNum)++;
		printf("pthread_id = %ld \t g_iNo = %d \t pNum = %d\n",pthread_self(),g_iNo,(*pNum));
	}

	pthread_mutex_unlock(&_lock);
}

int main()
{
	int i;
	pthread_t tid[2];
	int Num = 100;

	pthread_mutex_init(&_lock,NULL);

	for(i = 0; i < 2;i++)
	{
		pthread_create(&tid[i],NULL,t_handler,(void *)&Num);
		
	}

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	
	pthread_mutex_destroy(&_lock);

	printf("\nIn Main thread \n");
	exit(0);
}