#pragma once
#include <list>
#include "Plugin.h"
#include "InputChannel.h"

class AudioInput
{
public:
	virtual void read(byte[]);
	void addPlugin(Plugin) const;
	void addListeningChannel(InputChannel) const;
	AudioInput();
	virtual ~AudioInput();
private:
	const char* name;
	bool enabled;

protected:
	std::list<Plugin> processingPlugins;
	std::list<InputChannel> listeningChannels;
	
};
