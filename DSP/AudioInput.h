#pragma once
#include <list>
#include "Plugin.h"
#include "InputChannel.h"

class AudioInput
{
public:
	virtual void read(byte[]);
	void addPlugin(Plugin);
	void addListeningChannel(InputChannel*);
	AudioInput(const char*);
	virtual ~AudioInput();
	std::list<Plugin> processingPlugins;
	std::list<InputChannel*> listeningChannels;
	const char* getName();
private:
	const char* name;
	bool enabled;

	
	
};
