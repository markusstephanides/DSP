#pragma once
#include "AudioOutput.h"

class AnalogAudioOutput : public AudioOutput
{
public:
	AnalogAudioOutput(int);
	~AnalogAudioOutput();
	void write(byte[]) override;
private:
	int hwIndex;
};
