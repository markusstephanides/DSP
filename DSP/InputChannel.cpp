#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"

void InputChannel::read(byte audioData[])
{
	Logger::log("5");
	int sum = 0;

	for (int i = 0; i < Utils::arrayLength(audioData); i++)
	{
		sum += audioData[i];
	}

	char* str = nullptr;
	snprintf(str, sizeof(str), "%i\n", sum);
	Logger::log(str);
	delete str;
}
