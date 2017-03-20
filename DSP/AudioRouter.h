#pragma once
#include <list>
#include "OutputChannel.h"

class AudioRouter
{
public:
	
private:
	std::list<OutputChannel> inputChannels;
	std::list<AudioOutput> audioOutputs;
};
