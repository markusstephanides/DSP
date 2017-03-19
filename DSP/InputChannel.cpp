#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"

void InputChannel::read(byte audioData[])
{
	Logger::log("5");
	int sum = 0;
	Logger::log("6");
	for (int i = 0; i < Utils::arrayLength(audioData); i++)
	{
		sum += audioData[i];
	}
	Logger::log("7");
	char* str = nullptr;
	Logger::log("7.1");
	snprintf(str, sizeof(str), "%i\n", sum);
	Logger::log("8");
	Logger::log(str);
	Logger::log("9");
}
