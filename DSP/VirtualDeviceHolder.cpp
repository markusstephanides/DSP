#include "VirtualDeviceHolder.h"
#include "UDPClient.h"

std::list<InputChannel*> VirtualDeviceHolder::inputChannels = std::list<InputChannel*>();
std::list<OutputChannel*> VirtualDeviceHolder::outputChannels = std::list<OutputChannel*>();
std::list<AudioInput*> VirtualDeviceHolder::audioInputs = std::list<AudioInput*>();
std::list<AudioOutput*> VirtualDeviceHolder::audioOutputs = std::list<AudioOutput*>();

bool VirtualDeviceHolder::init()
{
	// Create inputs - TODO This should be configureable
	audioInputs.push_back(UDPClient::registerDigitalInput(0, "Player A"));
	audioInputs.push_back(UDPClient::registerDigitalInput(1, "Player B"));
	audioInputs.push_back(UDPClient::registerDigitalInput(2, "Cart 1"));
	audioInputs.push_back(UDPClient::registerDigitalInput(3, "Cart 2"));
	audioInputs.push_back(UDPClient::registerDigitalInput(4, "Cart 3"));
	audioInputs.push_back(UDPClient::registerDigitalInput(5, "Cart 4"));
	audioInputs.push_back(UDPClient::registerDigitalInput(10, "PC Sounds"));
	audioInputs.push_back(UDPClient::registerDigitalInput(11, "PPFL"));
	audioInputs.push_back(UDPClient::registerDigitalInput(12, "Voice"));

	// Create input channels
	inputChannels.push_back(new InputChannel(getAudioInput("Player A")));
	inputChannels.push_back(new InputChannel(getAudioInput("Player B")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 1")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 2")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 3")));
	inputChannels.push_back(new InputChannel(getAudioInput("PC Sounds")));
	inputChannels.push_back(new InputChannel(getAudioInput("PPFL")));
	inputChannels.push_back(new InputChannel(getAudioInput("Voice")));

	inputChannels.push_back(new InputChannel(getAudioInput("Player A")));
	inputChannels.push_back(new InputChannel(getAudioInput("Player B")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 1")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 2")));
	inputChannels.push_back(new InputChannel(getAudioInput("Cart 3")));
	inputChannels.push_back(new InputChannel(getAudioInput("PC Sounds")));
	inputChannels.push_back(new InputChannel(getAudioInput("PPFL")));
	inputChannels.push_back(new InputChannel(getAudioInput("Voice")));


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
	audioInputs.push_back(UDPClient::registerDigitalInput(channelId, name));
	get
}
