#pragma once
#include "../PortAudio/portaudio.h"
#include <list>

class AnalogAudioSystem
{
public:
	static void init();
	static PaStream* openOutputStream(int);
	static void shutdown();

private:
	static std::list<PaStream*> openStreams;
};
