#pragma once
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>


#define PORT 9000 

class AudanSyncClient
{
public:
	static unsigned long currentMs;
	static bool start();
	static void stop();
	static void deallocate();

private:
	static void listen();
	static bool listening;
	static int socketId;
};
