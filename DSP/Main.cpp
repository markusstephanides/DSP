#include <stdio.h>
#include "Channel.h"
#include "Logger.h"

int main() {
	Logger::log("Starting DSP firmware!");
	Logger::log("Reading configuration...");
	Channel channel = Channel();

	getchar();
	
	return 0;
}
