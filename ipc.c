#include "ipc.h"

void InitSem(int semId, int value)
{
    union semun tmp;
    tmp.val = value;
    if(semctl(semId,0,SETVAL,tmp) == -1){
        perror("sem init error!");
        exit(-1);
    }
}

void CreateSem(key_t key)
{
    int semId;
    semId = semget(key, 1, IPC_CREAT | 0666);
    InitSem(semId, 1);
}

void PSem(int semId)
{
    struct sembuf sbuf;
    
    sbuf.sem_num = 0; /*序号*/
    sbuf.sem_op = -1; /* p操作*/
    sbuf.sem_flg = SEM_UNDO; /*？*/

    if(semop(semId, &sbuf, 1) == -1){
        perror("P sem failed");
        exit(-1);
    }
}

void VSem(int semId)
{
    struct sembuf sbuf;
    
    sbuf.sem_num = 0; /*序号*/
    sbuf.sem_op = 1; /* v操作*/
    sbuf.sem_flg = SEM_UNDO; /*？*/

    /*
        int semop(int semid, struct sembuf *sops, size_t nsops);
        struct sembuf{
            unsigned short sem_num;
            short sem_op;
            short sem_flg; // IPC_NOWAIT, SEM_UNDO will be auto undone when the process terminates
        }  
    */
    if(semop(semId, &sbuf, 1) == -1){
        perror("V sem failed");
        exit(-1);
    }
}

void DelSem(int semId)
{
    union semun tmp;
    /*
    // IPC_RMID immediately remove the semaphore set, awakening 
    // all processes blocked in semop calls on the set
    是否设计多进程间同步的问题呢？
    */
    if(semctl(semId, 0, IPC_RMID, tmp) == -1){
        perror("Del sem failed");
        exit(-1);
    }
}