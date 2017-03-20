#pragma once
#include "Utils.h"
#include "OutputChannel.h"

class AudioRoute
{
public:
	AudioRoute(const char*, const char*);
	bool setMuted(bool);
	void write(byte[]);
private:
	bool muted;
	OutputChannel from;
	AudioOutput to;
};
