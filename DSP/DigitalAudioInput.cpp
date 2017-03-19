#include "DigitalAudioInput.h"
#include "Logger.h"

DigitalAudioInput::DigitalAudioInput(int inputId_)
{
	this->inputId = inputId_;
}

DigitalAudioInput::~DigitalAudioInput()
{

}

int DigitalAudioInput::getInputId() const
{	
	return this->inputId;
}

void DigitalAudioInput::read(byte audioData[])
{
	Logger::log("2");
	// first process the audio signals
	for (Plugin plugin : this->processingPlugins)
	{
		plugin.process(audioData);
	}

	Logger::log("3");

	// then send the processed signals to the channels
	for (InputChannel channel : this->listeningChannels)
	{
		channel.read(audioData);
	}

	Logger::log("4");
}

