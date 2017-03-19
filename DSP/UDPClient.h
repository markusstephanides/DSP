﻿#pragma once
#include "DigitalAudioInput.h"
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>


#define BUFLEN 1922  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data


class UDPClient
{
public:
	UDPClient();
	~UDPClient();
	static DigitalAudioInput* registerDigitalInput(int inputId);
	static void start();
	static void stop();
	static void deallocate();
private:
	static std::list<DigitalAudioInput*> registeredDigitalInputs;
	static void listen();
	static bool listening;
	static int socketId;
	static void processAudioDataPacket(byte[]);
};
