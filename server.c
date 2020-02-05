#include "ipc.h"


int main()
{
	int semId, shmId, msgId, keyId;
	char *shm = NULL;
	struct shmid_ds buf1;
	struct msqid_ds buf2;
	IpcMsgBuf msg;
	
	keyId = ftok("./", 0);
	printf("%d\n", keyId);

	msgId = msgget(keyId, 0666| IPC_CREAT);
	assert(msgId != -1);
	printf("msgId: %d\n", msgId);
	
	semId = semget(keyId, 1, IPC_CREAT | 0666);
	InitSem(semId, 1);

	shmId = shmget(keyId, 1024, IPC_CREAT | 0666);
	shm = (char *)shmat(shmId, 0, 0);
	
	

	IpcMsgBuf data;
	memset(&data,0,sizeof(IpcMsgBuf));
	while(1){
		msgrcv(msgId, &msg,sizeof(IpcMsgBuf),1000,0);
		if(msg.mtext[0] == 'q'){
			printf("ipc quit\n");
			break;
		}
		if(msg.mtext[0] == 'r'){
			PSem(semId);
			printf("shared mem: %s\n", shm);
			VSem(semId);
		}
	}

	shmdt(shm);
	shmctl(shmId, IPC_RMID, &buf1);
	msgctl(msgId, IPC_RMID, &buf2);
	DelSem(semId);

	return 0;
}
