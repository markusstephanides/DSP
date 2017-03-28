#pragma once

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
