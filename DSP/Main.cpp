#include <stdio.h>
#include "Channel.h"
#include "Logger.h"
#include "UI.h"
#include "DigitalAudioInput.h"
#include "UDPClient.h"
#include <iostream>
#include "AnalogAudioSystem.h"

int main() {
	Logger::log("Starting DSP firmware!");

	AnalogAudioSystem::init();

	// to test the audan interface, we create a digital audio input along with some channels
	DigitalAudioInput* digital_audio_input = UDPClient::registerDigitalInput(10);
	InputChannel channel = InputChannel();
	digital_audio_input->addListeningChannel(channel);

	UDPClient::start();

	Logger::log("Waiting for user input...");
	getchar();
	Logger::log("A");
	AnalogAudioSystem::shutdown();
	Logger::log("B");
	delete digital_audio_input;
	Logger::log("C");
	UDPClient::deallocate();
	Logger::log("D");
	return 0;
}
