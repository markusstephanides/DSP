#include <stdio.h>
#include "Channel.h"
#include "Logger.h"
#include "UI.h"
#include "DigitalAudioInput.h"
#include "UDPClient.h"

int main() {
	Logger::log("Starting DSP firmware!");


	// to test the audan interface, we create a digital audio input along with some channels
	DigitalAudioInput* digital_audio_input = UDPClient::registerDigitalInput(0);
	InputChannel channel = InputChannel();
	digital_audio_input->addListeningChannel(channel);

	Logger::log("Waiting for user input...");
	getchar();
	//delete digital_audio_input;
	UDPClient::deallocate();

	
	
	return 0;
}
