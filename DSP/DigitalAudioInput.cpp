﻿#include "DigitalAudioInput.h"
#include "Logger.h"

DigitalAudioInput::DigitalAudioInput(int inputId_, const char* name) : inputId(inputId_), AudioInput(name)
{

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
	// first process the audio signals
	for (Plugin plugin : this->processingPlugins)
	{
		plugin.process(audioData);
	}

	// then send the processed signals to the channels
	for (InputChannel channel : this->listeningChannels)
	{
		channel.read(audioData);
	}

}

