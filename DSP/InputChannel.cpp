#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"
#include "Constants.h"
#include "VirtualDeviceHolder.h"

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
	VirtualDeviceHolder::getAudioOutput("Monitor")->write(audioData);

}
