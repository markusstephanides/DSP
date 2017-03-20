#pragma once
#include <list>
#include "InputChannel.h"
#include "OutputChannel.h"
#include "AudioInput.h"

class VirtualDeviceHolder
{
public:
	static bool init();
	static InputChannel* getInputChannel(const char* name);
	static OutputChannel* getOutputChannel(const char* name);

	static AudioInput* getAudioInput(const char* name);
	static AudioOutput* getAudioOutput(const char* name);

	static void createDigitalInputChannelOutputChannel(byte, const char*);
private:
	static std::list<InputChannel*> inputChannels;
	static std::list<OutputChannel*> outputChannels;

	static std::list<AudioInput*> audioInputs;
	static std::list<AudioOutput*> audioOutputs;
};
