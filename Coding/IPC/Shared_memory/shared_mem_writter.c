#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define BUFF_SIZE	1024
#define SHM_KEY		0x1234
#define OBJ_PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)	//permissions for shm_msg
/*
									  Octal   Binary		  Decimal
S_IRUSR : STAT INODE READ USER		: 0400	: 0100000000	: 256
S_IWUSR : STAT INODE WRITE USER		: 0200	: 0010000000	: 128
S_IRGRP : STAT INODE READ GROUP		: 040	: 0000100000	: 32
S_IWGRP : STAT INODE WRITE GROUP	: 020	: 0000010000	: 16
									-----------------------------
									: 0660	: 0110110000	:432
*/
struct shm_msg
{
	int count;
	int complete;
	char buff[BUFF_SIZE];
};

int main()
{
	int shmid;
	struct shm_msg *pShm = NULL;
	char pBuff[BUFF_SIZE];

	shmid = shmget(SHM_KEY,sizeof(struct shm_msg),IPC_CREAT | OBJ_PERMISSIONS);
	if(shmid == -1)
	{
		perror("shmget FAILED !");
		exit(1);
	}
	
 	/*
        void *shmat(int shmid, const void *shmaddr, int shmflg);
        If shmaddr is NULL, then the segment is attached at a suitable address selected by the kernel.
        shmat() returns the address at which the shared memory segment is attached. -->shmp
    */
  
  	pShm = shmat(shmid,NULL,0);
  	if(pShm == (void *)-1)
  	{
  		perror("Shared memory attach FAILED !");
  		exit(1);
  	}

  	/*Transfer data from buffer to shared memory*/
  	printf("Enter data to stored in Shared Memory : ");
  	gets(pBuff);

  	pShm->count = strlen(pBuff);
  	printf("count : %d\n",pShm->count);
    strcpy(pShm->buff,pBuff);
    printf("buff : %s\n",pShm->buff);

  	pShm->complete = 1;

  	sleep(5);

  	if(shmdt(pShm) == -1)
  	{
  		perror("shmdt FAILED");
  		exit(1);
  	}

  	if(shmctl(shmid,IPC_RMID,0) == -1)
  	{
  		perror("shmctl FAILED");
  		exit(1);
  	}
  	
  	printf("\nBye Bye\n");

  	exit(0);
}
