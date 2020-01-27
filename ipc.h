#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define IPC_MSG_BUF_LEN 512

typedef struct {
	long mtype;
	char mtext[IPC_MSG_BUF_LEN];
}IpcMsgBuf;


