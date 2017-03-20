#include "AudioRoute.h"

AudioRoute::AudioRoute(const char* fromOutputChannel, const char* toAudioOutput): muted(false)
{

}

bool AudioRoute::setMuted(bool muted_)
{
	this->muted = muted_;
}

void AudioRoute::write(byte audioData[])
{
	if (this->muted) return;

	this->to.write(audioData);
}
