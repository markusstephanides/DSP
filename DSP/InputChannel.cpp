#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"
#include "Constants.h"
#include "VirtualDeviceHolder.h"
#include <iostream>

InputChannel::InputChannel(const char* name): Channel(name)
{
}

void InputChannel::read(byte audioData[])
{
	int sum = 0;
	for (int i = 0; i < Constants::AUDIO_BUFFER_SIZE; i++)
	{
		sum += audioData[i];
	}

	//printf("Length: %i - Sum::: %i\n", 1920, sum);
	Logger::log("Before out!!!");
	std::cout << VirtualDeviceHolder::getAudioOutput("Monitor") << std::endl;
	VirtualDeviceHolder::getAudioOutput("Monitor")->write(audioData);
	Logger::log("after out");

}
