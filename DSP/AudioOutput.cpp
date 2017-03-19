#include "AudioOutput.h"
#include <stdio.h>

AudioOutput::AudioOutput(const char* name) : name(name), enabled(false)
{
}

AudioOutput::~AudioOutput()
{
}

void AudioOutput::write(byte[])
{
	printf("BASE WRITE!\n");
}
