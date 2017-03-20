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
	this->listeningChannels.push_back(channel);
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
