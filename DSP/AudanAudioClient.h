#pragma once
#include "DigitalAudioInput.h"
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>

#define PORT 8888   //The port on which to listen for incoming data


class AudanAudioClient
{
public:
	static DigitalAudioInput* registerDigitalInput(byte inputId, const char*);
	static bool start();
	static void stop();
	static void deallocate();
private:
	static std::list<DigitalAudioInput*> registeredDigitalInputs;
	static void listen();
	static bool listening;
	static int socketId;
	static void processAudioDataPacket(byte[]);
};
