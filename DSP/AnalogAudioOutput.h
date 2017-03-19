#pragma once
#include "AudioOutput.h"
#include "../PortAudio/portaudio.h"


class AnalogAudioOutput : public AudioOutput
{
public:
	AnalogAudioOutput(int, const char*);
	~AnalogAudioOutput();
	void write(byte[]) override;
private:
	int hwIndex;
	PaStream* stream;
};
