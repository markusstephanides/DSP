#pragma once
#include "AudioOutput.h"
#include "../PortAudio/portaudio.h"


class AnalogAudioOutput : public AudioOutput
{
public:
	AnalogAudioOutput(int, const char*);
	~AnalogAudioOutput();
	void write(byte[]) override;
	static int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);
private:
	int hwIndex;
	PaStream* stream;
};
