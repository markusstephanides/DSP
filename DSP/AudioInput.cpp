#include "AudioInput.h"
#include <stdio.h>

void AudioInput::read(char[])
{
}

void AudioInput::addPlugin(Plugin plugin)
{
	this->processingPlugins.push_back(plugin);
}

void AudioInput::addListeningChannel(InputChannel channel)
{
	printf("a!\n");
	this->listeningChannels.push_back(channel);
	printf("b\n");
}

AudioInput::AudioInput()
{
}

AudioInput::~AudioInput()
{
	delete this->name;
}
