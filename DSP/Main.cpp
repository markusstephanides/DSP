#include <stdio.h>
#include "Channel.h"
#include "Logger.h"
#include "UI.h"
#include "DigitalAudioInput.h"
#include "AudanAudioClient.h"
#include <iostream>
#include "AnalogAudioSystem.h"
#include "VirtualDeviceHolder.h"
#include "AudanSyncClient.h"

int main() {
	Logger::log("Starting DSP!");

	//Initialize the analog audio 
	if(!AnalogAudioSystem::init())
	{
		Logger::log("Failed to initialize the analog audio system! Aborting startup...");
		return 0;
	}
	//Initialize the virtual device holder
	if(!VirtualDeviceHolder::init())
	{
		Logger::log("Failed to initialize the virtual device holder! Aborting startup...");
		return 0;
	}

	//Start the sync client
	if (!AudanSyncClient::start())
	{
		Logger::log("Failed to start the audan client! Aborting startup...");
		return 0;
	}

	//Start the audio client
	if(!AudanAudioClient::start())
	{
		Logger::log("Failed to start the audan sync client! Aborting startup...");
		return 0;
	}	
	
	Logger::log("DSP is ready!");
	Logger::log("Waiting for user input...");
	getchar();
	AnalogAudioSystem::shutdown();
	AudanAudioClient::deallocate();
	AudanSyncClient::deallocate();
	Logger::log("The DSP has been shutdown. Bye!");
	return 0;
}
