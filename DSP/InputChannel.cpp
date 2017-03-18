#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"

void InputChannel::read(byte audioData[])
{
	const char* str = "";
	sprintf_s(str, sizeof(str), "[INPUTCHANNEL] Read %i bytes", Utils::arrayLength(audioData));
	Logger::log(str);
}
