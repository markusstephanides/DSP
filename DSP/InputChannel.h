#pragma once
#include "Channel.h"
#include "Utils.h"

class InputChannel : public Channel
{
public:
	static void read(byte audioData[]);
};
