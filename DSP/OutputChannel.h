#pragma once
#include "Utils.h"
#include "Channel.h"
#include "AudioOutput.h"

class InputChannel;

class OutputChannel : public Channel
{
public:
	explicit OutputChannel(const char*);
	explicit OutputChannel(InputChannel*);
	void write(byte audioData[]);

private:
	std::list<AudioOutput> outputs;

};
