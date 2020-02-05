all:
	gcc -o server -g -I. server.c ipc.c
	gcc -o client -g -I. client.c ipc.c
clean:
	rm server client
