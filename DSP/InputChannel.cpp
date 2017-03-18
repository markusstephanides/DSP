#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"

void InputChannel::read(byte audioData[])
{
	char* str = nullptr;
	snprintf(str, sizeof(str), "[INPUTCHANNEL] Read %i bytes", Utils::arrayLength(audioData));
	Logger::log(str);
	delete str;
}
