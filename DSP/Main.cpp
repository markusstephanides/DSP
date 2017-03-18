#include <stdio.h>
#include "Channel.h"
#include "Logger.h"
#include "UI.h"
#include "DigitalAudioInput.h"
#include "UDPClient.h"
#include <iostream>

int main() {
	Logger::log("Starting DSP firmware!");


	// to test the audan interface, we create a digital audio input along with some channels
	DigitalAudioInput* digital_audio_input = UDPClient::registerDigitalInput(0);
	InputChannel channel = InputChannel();
	std::cout << digital_audio_input << std::endl;
	std::cout << "Before pointer dings" << std::endl;
	digital_audio_input->addListeningChannel(channel);

	Logger::log("Waiting for user input...");
	getchar();
	Logger::log("3");
	delete digital_audio_input;
	Logger::log("4");
	UDPClient::deallocate();
	Logger::log("5");
	return 0;
}
