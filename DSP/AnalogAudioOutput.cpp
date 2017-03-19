#include "AnalogAudioOutput.h"
#include "AnalogAudioSystem.h"

#include <cstdio>
#include <ostream>
#include <iostream>

AnalogAudioOutput::AnalogAudioOutput(int hwIndex, const char* name) : AudioOutput(name)
{
	this->hwIndex = hwIndex;

	this->stream = AnalogAudioSystem::openOutputStream(1);
	printf("Afer stream open!\n");
	std::cout << this->stream << std::endl;
}

AnalogAudioOutput::~AnalogAudioOutput()
{
}

void AnalogAudioOutput::write(byte audioData[])
{
	int sum = 0;
	for (int i = 0; i < 1920; i++)
	{
		sum += audioData[i];
	}

	printf("WRITE Length: %i - Sum: %i\n", 1920, sum);

	//printf("Write!\n");
	Pa_WriteStream(this->stream, audioData, 480);
}
