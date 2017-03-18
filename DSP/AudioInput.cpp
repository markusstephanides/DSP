#include "AudioInput.h"


void AudioInput::read(char[])
{
}

void AudioInput::addPlugin(Plugin plugin)
{
	this->processingPlugins.push_back(plugin);
}

void AudioInput::addListeningChannel(InputChannel channel)
{
	this->listeningChannels.push_back(channel);
}

AudioInput::AudioInput()
{
}

AudioInput::~AudioInput()
{
	delete this->name;
}
