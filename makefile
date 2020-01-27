all:
	gcc -o server -g -I. server.c
	gcc -o client -g -I. client.c
