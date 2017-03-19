#pragma once
#include <list>
#include "Plugin.h"
#include "InputChannel.h"

class AudioInput
{
public:
	virtual void read(byte[]);
	void addPlugin(Plugin);
	void addListeningChannel(InputChannel);
	AudioInput();
	virtual ~AudioInput();
	std::list<Plugin> processingPlugins;
	std::list<InputChannel> listeningChannels;
private:
	const char* name;
	bool enabled;

	
	
};
