#include "OutputChannel.h"
#include "InputChannel.h"

OutputChannel::OutputChannel(const char* name) : Channel(name)
{
}

OutputChannel::OutputChannel(InputChannel* inputChannel) : Channel(inputChannel->getName())
{
	
}

void OutputChannel::write(byte audioData[])
{
	for (AudioOutput output : outputs)
	{
		output.write(audioData);
	}
}

