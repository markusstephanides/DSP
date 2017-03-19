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

	//AnalogAudioSystem::init();

	// to test the audan interface, we create a digital audio input along with some channels
	Logger::log("1");
	DigitalAudioInput* digital_audio_input = UDPClient::registerDigitalInput(10);
	Logger::log("2");
	InputChannel channel = InputChannel();
	Logger::log("3");
	std::cout << &channel << std::endl;
	digital_audio_input->addListeningChannel(channel);
	Logger::log("4");
	UDPClient::start();
	Logger::log("5");
	Logger::log("Waiting for user input...");
	getchar();
	AnalogAudioSystem::shutdown();
	UDPClient::deallocate();
	return 0;
}
