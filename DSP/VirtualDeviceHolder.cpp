#include "VirtualDeviceHolder.h"
#include "UDPClient.h"
#include "Logger.h"
#include <iostream>

std::list<InputChannel*> VirtualDeviceHolder::inputChannels = std::list<InputChannel*>();
std::list<OutputChannel*> VirtualDeviceHolder::outputChannels = std::list<OutputChannel*>();
std::list<AudioInput*> VirtualDeviceHolder::audioInputs = std::list<AudioInput*>();
std::list<AudioOutput*> VirtualDeviceHolder::audioOutputs = std::list<AudioOutput*>();

bool VirtualDeviceHolder::init()
{

	audioOutputs.push_back(new AnalogAudioOutput(1, "Monitor"));
	// Create default inputs channels
	/*createDigitalInputChannelOutputChannel(0, "Player A");
	createDigitalInputChannelOutputChannel(1, "Player B");
	createDigitalInputChannelOutputChannel(2, "Cart 1");
	createDigitalInputChannelOutputChannel(3, "Cart 2");
	createDigitalInputChannelOutputChannel(4, "Cart 3");
	createDigitalInputChannelOutputChannel(5, "Cart 4");*/
	createDigitalInputChannelOutputChannel(9, "PC Sounds (DX)");
	//createDigitalInputChannelOutputChannel(10, "PC Sounds");
	/*createDigitalInputChannelOutputChannel(11, "PPFL");
	createDigitalInputChannelOutputChannel(12, "Voice");*/


	// TODO Add MIC1 and MIC2 analog inputs



	return true;
}

InputChannel* VirtualDeviceHolder::getInputChannel(const char* name)
{
	for (InputChannel* inputChannel : inputChannels)
	{
		if (strcmp(inputChannel->getName(), name) == 0) {
			return inputChannel;
		}
	}

	return nullptr;
}

OutputChannel* VirtualDeviceHolder::getOutputChannel(const char* name)
{
	for (OutputChannel* outputChannel : outputChannels)
	{
		if (strcmp(outputChannel->getName(), name) == 0) {
			return outputChannel;
		}
	}

	return nullptr;
}

AudioInput* VirtualDeviceHolder::getAudioInput(const char* name)
{
	for (AudioInput* audioInput : audioInputs)
	{
		if (strcmp(audioInput->getName(), name) == 0) {
			return audioInput;
		}
	}

	return nullptr;
}

AudioOutput* VirtualDeviceHolder::getAudioOutput(const char* name)
{
	for (AudioOutput* audioOutput : audioOutputs)
	{
		if (strcmp(audioOutput->getName(), name) == 0) {
			return audioOutput;
		}
	}

	return nullptr;
}

void VirtualDeviceHolder::createDigitalInputChannelOutputChannel(byte channelId, const char* name)
{
	inputChannels.push_back(new InputChannel(name));
	audioInputs.push_back(UDPClient::registerDigitalInput(channelId, name));
	getAudioInput(name)->addListeningChannel(getInputChannel(name));
}
