#pragma once
#include "DigitalAudioInput.h"
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>


#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data


class UDPClient
{
public:
	static DigitalAudioInput* registerDigitalInput(int inputId);
	static void start();
private:
	static std::list<DigitalAudioInput> registeredDigitalInputs;
};
