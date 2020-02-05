#include "ipc.h"

int main()
{
	int keyId, shmId, semId, msgId;
	char *shm = NULL;
	// struct msg_form msg;

	keyId= ftok("./", 0);
	printf("%d\n", keyId);

	msgId = msgget(keyId,0666 | IPC_CREAT);
	assert(msgId != -1);
	printf("msgId: %d\n",msgId);

	shmId = shmget(keyId, 1024, 0);
	shm = (char *)shmat(shmId, 0, 0);

	semId = semget(keyId, 0, 0);

	IpcMsgBuf data;
	data.mtype = 1000;
	data.mtext[0] = 'r';
	PSem(semId);
	char *str =  "hello shared memory";
	memcpy(shm, str, 20);
	VSem(semId);
	msgsnd(msgId, &data, sizeof(IpcMsgBuf), 0);

	data.mtype = 1000;
	data.mtext[0] = 'q';
	msgsnd(msgId, &data, sizeof(IpcMsgBuf), 0);
	
	shmdt(shm);

	return 0;
}
