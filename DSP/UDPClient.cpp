#include "UDPClient.h"
#include "Logger.h"
#include <ostream>
#include <iostream>
#include <thread>

std::list<DigitalAudioInput*> UDPClient::registeredDigitalInputs = std::list<DigitalAudioInput*>();

DigitalAudioInput* UDPClient::registerDigitalInput(int inputId)
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
	DigitalAudioInput* input = new DigitalAudioInput(inputId);
	registeredDigitalInputs.push_back(input);
	return input;
}

void die(const char *s)
{
	Logger::log(s);
}

void UDPClient::start()
{
	struct sockaddr_in si_me, si_other;

	int s, i;
	socklen_t slen = socklen_t(sizeof(si_other));
	socklen_t recv_len;

	char buf[BUFLEN];

	//create a UDP socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}

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

	std::thread listeningThread(listen, s);
}

void UDPClient::stop()
{
	listening = false;
}


void UDPClient::deallocate()
{
	if (listening) stop();
	registeredDigitalInputs.clear();
}

void UDPClient::listen(int socket)
{
	Logger::log("UDP client started listening");
	listening = true;

	//keep listening for data
	while (listening)
	{
		printf("Waiting for data...");
		fflush(stdout);

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, reinterpret_cast<struct sockaddr*>(&si_other), &slen)) == -1)
		{
			die("recvfrom()");
		}

		//print details of the client/peer and the data received
		printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printf("Data: %s\n", buf);

		//now reply the client with the same data
		if (sendto(s, buf, recv_len, 0, reinterpret_cast<struct sockaddr*>(&si_other), slen) == -1)
		{
			die("sendto()");
		}
	}

	Logger::log("UDP client stopped listening");
	close(socket);
}
