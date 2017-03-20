#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"

InputChannel::InputChannel(const char* name): Channel(name)
{
	output_ = new AnalogAudioOutput(1, "DX2000");
}

InputChannel::InputChannel(AudioInput* input) : Channel(input->getName())
{
	input->addListeningChannel(this);
}

void InputChannel::read(byte audioData[])
{
	int sum = 0;
	for (int i = 0; i < BUFSIZE; i++)
	{
		sum += audioData[i];
	}

	//printf("Length: %i - Sum::: %i\n", 1920, sum);
	output_->write(audioData);

}
