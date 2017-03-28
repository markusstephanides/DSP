#include "AudanSyncClient.h"
#include "Logger.h"
#include "Constants.h"
#include "Utils.h"
#include <thread>
#include <iostream>

void die(const char *s)
{
	Logger::log(s);
}

bool AudanSyncClient::start()
{
	std::thread(listen).detach();
	return true;
}

void AudanSyncClient::stop()
{
	listening = false;
	close(socketId);
}


void AudanSyncClient::deallocate()
{
	if (listening) {
		stop();
		Logger::log("Deallocating AudanAudioClient after it was stopped!");
	}
	else Logger::log("Deallocating AudanAudioClient!");
}

void AudanSyncClient::listen()
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
	if (std::bind(s, reinterpret_cast<struct sockaddr*>(&si_me), sizeof(si_me)) == -1)
	{
		die("bind");
	}

	Logger::log("AudanSyncClient started listening");
	listening = true;


	//keep listening for data
	while (listening)
	{

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, Constants::NET_BUFFER_SIZE, 0, reinterpret_cast<struct sockaddr*>(&si_other), &slen)) == -1)
		{
			die("recvfrom()");
		}

		currentMs = *static_cast<unsigned long*>(buf);
		std::cout << currentMs << std::endl;

	}

	Logger::log("AudanSyncClient stopped listening");
}