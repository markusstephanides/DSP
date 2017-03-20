#include "UDPClient.h"
#include "Logger.h"
#include <ostream>
#include <iostream>
#include <thread>
#include <future>
#include "Constants.h"

std::list<DigitalAudioInput*> UDPClient::registeredDigitalInputs = std::list<DigitalAudioInput*>();
bool UDPClient::listening = false;
int UDPClient::socketId = -1;

DigitalAudioInput* UDPClient::registerDigitalInput(byte inputId, const char* name)
{
	for (auto audio_input : registeredDigitalInputs)
	{
		if (audio_input->getInputId() == inputId)
		{
			// there is already a digital input with that inputId
			return nullptr;
		}
	}

	// there are no digital inputs with that inputId
	DigitalAudioInput* input = new DigitalAudioInput(inputId, name);
	registeredDigitalInputs.push_back(input);
	return input;
}

void die(const char *s)
{
	Logger::log(s);
}

bool UDPClient::start()
{
	std::thread(listen).detach();
	return true;
}

void UDPClient::stop()
{
	listening = false;
	close(socketId);

}


void UDPClient::deallocate()
{
	if (listening) {
		stop();
		Logger::log("Deallocating UDPClient after it was stopped!");
	}
	else Logger::log("Deallocating UDPClient!");
	registeredDigitalInputs.clear();
}

void UDPClient::listen()
{
	struct sockaddr_in si_me, si_other;

	int s, i;
	socklen_t slen = socklen_t(sizeof(si_other));
	socklen_t recv_len;

	byte buf[Constants::NET_BUFFER_SIZE];

	//create a UDP socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}

	socketId = s;

	// zero out the structure
	memset((char *)&si_me, 0, sizeof(si_me));

	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);

	//bind socket to port
	if (bind(s, reinterpret_cast<struct sockaddr*>(&si_me), sizeof(si_me)) == -1)
	{
		die("bind");
	}

	Logger::log("UDP client started listening");
	listening = true;


	//keep listening for data
	while (listening)
	{

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, Constants::NET_BUFFER_SIZE, 0, reinterpret_cast<struct sockaddr*>(&si_other), &slen)) == -1)
		{
			die("recvfrom()");
		}
	
		int pktId = buf[0];
		
		switch (pktId)
		{
		case 1:
			processAudioDataPacket(buf);
			break;
		default: break;
		}



		//print details of the client/peer and the data received
		//printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		//printf("Data: %s\n", buf);

		//now reply the client with the same data
		/*if (sendto(s, buf, recv_len, 0, reinterpret_cast<struct sockaddr*>(&si_other), slen) == -1)
		{
			die("sendto()");
		}*/
	}

	Logger::log("UDP client stopped listening");
}

void UDPClient::processAudioDataPacket(byte buf[])
{
	// the buffer has the packet type at index 0, the channel id at the last index
	byte channelId = buf[Constants::NET_BUFFER_SIZE - 1];
	//printf("Received audio data packet for channel: %i", channelId);
	byte audioData[Constants::AUDIO_BUFFER_SIZE];

	for(int i = 0; i < Constants::AUDIO_BUFFER_SIZE; i++)
	{
		audioData[i] = buf[i + 1];
	}


	for (DigitalAudioInput* input : registeredDigitalInputs)
	{
		if(input->getInputId() == channelId)
		{
			input->read(audioData);
			return;
		}
	}
}
