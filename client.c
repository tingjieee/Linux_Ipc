#include "ipc.h"

int main()
{
	int keyId = ftok("./", 0);
	printf("%d\n", keyId);

	int msgId = msgget(keyId,0666 | IPC_CREAT);
	assert(msgId != -1);
	printf("msgId: %d\n",msgId);

	IpcMsgBuf data;
	memset(&data, 0, sizeof(IpcMsgBuf));
	msgrcv(msgId, &data, sizeof(IpcMsgBuf),1000,0);
	printf("type = %d, text = %s\n", data.mtype, data.mtext);

	return 0;
}
