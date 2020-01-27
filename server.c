#include "ipc.h"

int main()
{
	int keyId = ftok("./", 0);
	printf("%d\n", keyId);

	int msgId = msgget(keyId, 0666| IPC_CREAT);
	assert(msgId != -1);
	printf("msgId: %d\n", msgId);
	
	IpcMsgBuf data;
	memset(&data,0,sizeof(IpcMsgBuf));

	data.mtype = 1000;
	strcpy(data.mtext, "Hello");
	msgsnd(msgId, &data, strlen(data.mtext)+sizeof(data.mtype), 0);
	memset(&data, 0, sizeof(data));
	printf("send hello\n");
	data.mtype = 2000;
	strcpy(data.mtext, "World\n");
	msgsnd(msgId, &data, strlen(data.mtext)+sizeof(data.mtype), 0);
	memset(&data, 0, sizeof(data));
	printf("send world\n");

	return 0;
}
