#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int g_iNo;

void * t_handler(void * vargs)
{
	int i;
	int * pNum = (int *)vargs;
	
	for(i = 0;i < 10;i++)
	{	
		g_iNo++;
		(*pNum)++;
		printf("pthread_id = %ld \t g_iNo = %d \t pNum = %d\n",pthread_self(),g_iNo,(*pNum));
	}
}

int main()
{
	int i;
	pthread_t tid[2];
	int Num = 100;

	for(i = 0; i < 2;i++)
	{
		pthread_create(&tid[i],NULL,t_handler,(void *)&Num);
		
	}

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	printf("\nIn Main thread \n");
	exit(0);
}