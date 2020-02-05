#version route 
1. basic ipc: can achieve 2 process communication
2. add semaphore and shared memory

n. 1.0 version: 
	achieve n process communication and 
	execute process hook function and
	shared memory between 2 process; have 2M msg transfor,


#debug route
process must have write/read permission

buf: long mtyp; char mtext[1];
mtype must > 0;


int msgsnd(int msgid, const void *msgp, size_t msgsz, int mgsflg);



ssize_t msgrcv(int msgid, void *msgp, size_t msgz, long msgtyp, int msgflg)

msgflg: IPC_NOWAIT; MSG_COPY; MSG_EXCEPT; MSG_NOERROR.

int msgget(key_t key, 0666 | IPC_CREAT);

0666
0: jinzhi
6: 110, read|write|exec
6: group group user
6: other user
