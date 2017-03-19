#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"

InputChannel::InputChannel(const char* name): Channel(name)
{
	output_ = static_cast<AudioOutput>(AnalogAudioOutput(1));
}

void InputChannel::read(byte audioData[])
{
	int sum = 0;

	for (int i = 0; i < Utils::arrayLength(audioData); i++)
	{
		sum += audioData[i];
	}

	printf("Sum::: %i\n", sum);
	output_.write(audioData);

}
