#include "AnalogAudioOutput.h"
#include "AnalogAudioSystem.h"

#include <cstdio>
#include <ostream>
#include <iostream>
#include "Constants.h"
#include <thread>

AnalogAudioOutput::AnalogAudioOutput(int hwIndex, const char* name) : AudioOutput(name)
{
	this->hwIndex = hwIndex;

	this->stream = AnalogAudioSystem::openOutputStream(hwIndex);
}

AnalogAudioOutput::~AnalogAudioOutput()
{

}

void AnalogAudioOutput::write(byte audioData[])
{
	/*int sum = 0;
	for (int i = 0; i < Constants::AUDIO_BUFFER_SIZE; i++)
	{
		sum += audioData[i];
	}

	printf("WRITE Length: %i - Sum: %i\n", Constants::AUDIO_BUFFER_SIZE, sum);*/

	//printf("Write!\n");

	std::thread(Pa_WriteStream, this->stream, audioData, 480).detach();
}
