#pragma once

#include <list>
#include "Plugin.h"

class AudioOutput
{
public:
	explicit AudioOutput(const char*);
	virtual ~AudioOutput();
	void addPlugin(Plugin);
	virtual void write(byte[]);
	const char* getName();
private:
	const char* name;
	bool enabled;

protected:
	std::list<Plugin> processingPlugins;

};
