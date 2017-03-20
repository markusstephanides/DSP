#pragma once
#include "Utils.h"
#include "Channel.h"
#include "AudioOutput.h"
#include "InputChannel.h"


class OutputChannel : public Channel
{
public:
	explicit OutputChannel(const char*);
	void write(byte audioData[]);

private:
	
};
