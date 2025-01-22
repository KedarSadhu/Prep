#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "binary_sems.h" /* Declares our binary semaphore functions */
#include "tlpi_hdr.h"

#define SHM_KEY 0x1234 /* Key for shared memory segment */
#define SEM_KEY 0x5678 /* Key for semaphore set */
#define OBJ_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)  /* Permissions for our IPC objects */

#define WRITE_SEM 0 /* Writer has access to shared memory */
#define READ_SEM 1 /* Reader has access to shared memory */

#ifndef BUF_SIZE /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024 /* Size of transfer buffer */
#endif

struct shmseg { /* Defines structure of shared memory segment */
int cnt; /* Number of bytes used in 'buf' */
char buf[BUF_SIZE]; /* Data being transferred */
};

#include "semun.h" /* Definition of semun union */
#include "svshm_xfr.h"

int main(int argc, char *argv[])
{
    int semid, shmid, bytes, xfrs;
    struct shmseg *shmp;
    union semun dummy;
   
    //semsphore
    semid = semget(SEM_KEY, 2, IPC_CREAT | OBJ_PERMS);
    if (semid == -1)
     errExit("semget");

    if (initSemAvailable(semid, WRITE_SEM) == -1)
        errExit("initSemAvailable");
    
    if (initSemInUse(semid, READ_SEM) == -1)
        errExit("initSemInUse");
    
    /*
        int shmget(key_t key, size_t size, int shmflg);

        IPC_CREAT : If no segment with the specified key exists, create a new segment

    */
    shmid = shmget(SHM_KEY, sizeof(struct shmseg), IPC_CREAT | OBJ_PERMS);
    if (shmid == -1)
        errExit("shmget");
   
    /*
        void *shmat(int shmid, const void *shmaddr, int shmflg);
        If shmaddr is NULL, then the segment is attached at a suitable address selected by the kernel.
        shmat() returns the address at which the shared memory segment is attached. -->shmp
    */
    shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *) -1)
        errExit("shmat");
   
    /* Transfer blocks of data from stdin to shared memory */
    for (xfrs = 0, bytes = 0; ; xfrs++, bytes += shmp->cnt)
    {
        if (reserveSem(semid, WRITE_SEM) == -1) /* Wait for our turn */
            errExit("reserveSem");
    
        shmp->cnt = read(STDIN_FILENO, shmp->buf, BUF_SIZE);
        if (shmp->cnt == -1)
            errExit("read");
    
        if (releaseSem(semid, READ_SEM) == -1) /* Give reader a turn */
            errExit("releaseSem");
    
        /* Have we reached EOF? We test this after giving the reader
        a turn so that it can see the 0 value in shmp->cnt. */
        if (shmp->cnt == 0)
            break;
    }
    
    /* Wait until reader has let us have one more turn. We then know
    reader has finished, and so we can delete the IPC objects. */
    if (reserveSem(semid, WRITE_SEM) == -1)
        errExit("reserveSem");
    
    if (semctl(semid, 0, IPC_RMID, dummy) == -1)
        errExit("semctl");
    
    if (shmdt(shmp) == -1)
        errExit("shmdt");
    
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        errExit("shmctl");
    
    fprintf(stderr, "Sent %d bytes (%d xfrs)\n", bytes, xfrs);
    
    exit(EXIT_SUCCESS);
}