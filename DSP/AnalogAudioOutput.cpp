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
	printf("Write!\n");
	//Pa_WriteStream(this->stream, audioData, 480);
}
