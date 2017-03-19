#pragma once

#include <list>
#include "Plugin.h"

class AudioOutput
{
public:
	AudioOutput();
	virtual ~AudioOutput();
	void addPlugin(Plugin);
	virtual void write(byte[]);

private:
	const char* name;
	bool enabled;

protected:
	std::list<Plugin> processingPlugins;

};
