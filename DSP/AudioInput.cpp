#include "AudioInput.h"


void AudioInput::read(char[])
{
}

void AudioInput::addPlugin(Plugin plugin) const
{
	this->addPlugin(plugin);
}

void AudioInput::addListeningChannel(InputChannel channel) const
{
	this->addListeningChannel(channel);
}

AudioInput::AudioInput()
{
}

AudioInput::~AudioInput()
{
	delete this->name;
}
