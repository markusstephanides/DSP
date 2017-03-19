#pragma once
#include "Channel.h"
#include "Utils.h"
#include "AudioOutput.h"
#include "AnalogAudioOutput.h"

class InputChannel : public Channel
{
public:
	explicit InputChannel(const char*);
	void read(byte audioData[]);

private: 
	AnalogAudioOutput output_;
};
