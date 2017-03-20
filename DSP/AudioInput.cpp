#include "AudioInput.h"
#include <stdio.h>

void AudioInput::read(char[])
{
}

void AudioInput::addPlugin(Plugin plugin)
{
	this->processingPlugins.push_back(plugin);
}

void AudioInput::addListeningChannel(InputChannel* channel)
{
	printf("a!\n");
	this->listeningChannels.push_back(channel);
	printf("b\n");
}

AudioInput::AudioInput(const char* name_) : name(name_), enabled(false)
{
}

AudioInput::~AudioInput()
{
}

const char* AudioInput::getName()
{
	return this->name;
}
