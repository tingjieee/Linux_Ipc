#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define IPC_MSG_BUF_LEN 512

typedef struct
{
	long mtype;
#if 0
	char mtext[IPC_MSG_BUF_LEN];
#else
	char mtext[1];
#endif
}IpcMsgBuf;

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

void CreateSem(key_t key);
void InitSem(int semId, int value);
void PSem(int semId);
void VSem(int semId);
void DelSem(int semId);
/*
	#include <sys/sem.h>
	int semget(key_t key, int num_sems, int sem_flags);
	int semop(int semid, struct sembuf semoparray[], size_t numops);
	int semctl(int semid, int sem_num, int cmd, ...);
*/
struct msg_form
{
	long mtype;
	char mtext;
};

/*
int shmget(key_t key, size_t size, int flag);
void *shmat(int shm_id,size_t size, int flag);
int shmdt(void *addr);
int shmctl(int shm_id, int cmd, struct shmid_ds *buf);
*/
