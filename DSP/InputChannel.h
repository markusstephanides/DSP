#pragma once
#include "Channel.h"
#include "Utils.h"
#include "AudioOutput.h"
#include "AnalogAudioOutput.h"
#include "AudioInput.h"

class InputChannel : public Channel
{
public:
	explicit InputChannel(const char*);
	explicit InputChannel(AudioInput*);
	void read(byte audioData[]);

private: 
	AnalogAudioOutput* output_;
};
