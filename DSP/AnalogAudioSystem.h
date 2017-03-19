#pragma once
#include "../PortAudio/portaudio.h"
#include <list>

class AnalogAudioSystem
{
public:
	static void init();
	static PaStream* openOutputStream(int, PaStreamCallback*, void*);
	static void shutdown();

private:
	static std::list<PaStream*> openStreams;
};
