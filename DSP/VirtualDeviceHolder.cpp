#include "VirtualDeviceHolder.h"
#include "UDPClient.h"

std::list<InputChannel*> VirtualDeviceHolder::inputChannels = std::list<InputChannel*>();
std::list<OutputChannel*> VirtualDeviceHolder::outputChannels = std::list<OutputChannel*>();
std::list<AudioInput*> VirtualDeviceHolder::audioInputs = std::list<AudioInput*>();
std::list<AudioOutput*> VirtualDeviceHolder::audioOutputs = std::list<AudioOutput*>();

bool VirtualDeviceHolder::init()
{
	// Create default inputs channels
	createDigitalInputChannelOutputChannel(0, "Player A");
	createDigitalInputChannelOutputChannel(1, "Player B");
	createDigitalInputChannelOutputChannel(2, "Cart 1");
	createDigitalInputChannelOutputChannel(3, "Cart 2");
	createDigitalInputChannelOutputChannel(4, "Cart 3");
	createDigitalInputChannelOutputChannel(5, "Cart 4");
	createDigitalInputChannelOutputChannel(10, "PC Sounds");
	createDigitalInputChannelOutputChannel(11, "PPFL");
	createDigitalInputChannelOutputChannel(12, "Voice");


	// TODO Add MIC1 and MIC2 analog inputs

	audioOutputs.push_back(new AnalogAudioOutput(1, "Monitor"));

	return true;
}

InputChannel* VirtualDeviceHolder::getInputChannel(const char* name)
{
	for (InputChannel* inputChannel : inputChannels)
	{
		if (inputChannel->getName() == name) return inputChannel;
	}

	return nullptr;
}

OutputChannel* VirtualDeviceHolder::getOutputChannel(const char* name)
{
	for (OutputChannel* outputChannel : outputChannels)
	{
		if (outputChannel->getName() == name) return outputChannel;
	}

	return nullptr;
}

AudioInput* VirtualDeviceHolder::getAudioInput(const char* name)
{
	for (AudioInput* audioInput : audioInputs)
	{
		if (audioInput->getName() == name) return audioInput;
	}

	return nullptr;
}

AudioOutput* VirtualDeviceHolder::getAudioOutput(const char* name)
{
	for (AudioOutput* audioOutput : audioOutputs)
	{
		if (audioOutput->getName() == name) return audioOutput;
	}

	return nullptr;
}

void VirtualDeviceHolder::createDigitalInputChannelOutputChannel(byte channelId, const char* name)
{
	inputChannels.push_back(new InputChannel(name));
	audioInputs.push_back(UDPClient::registerDigitalInput(channelId, name));
	getAudioInput(name)->addListeningChannel(getInputChannel(name));
}
