#pragma once
#include "Channel.h"
#include "Utils.h"
#include "AudioOutput.h"

class InputChannel : public Channel
{
public:
	InputChannel();
	void read(byte audioData[]);

private: 
	//AudioOutput output_;
};
