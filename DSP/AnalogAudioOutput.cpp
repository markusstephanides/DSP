#include "AnalogAudioOutput.h"

AnalogAudioOutput::AnalogAudioOutput(int hwIndex)
{
	this->hwIndex = hwIndex;
}

AnalogAudioOutput::~AnalogAudioOutput()
{
}

void AnalogAudioOutput::write(byte audioData[])
{

}
