#include "GainPlugin.h"
#include "Logger.h"
#include <cstdio>

void GainPlugin::process(byte audioData[])
{
	char* str = "";
	snprintf(str, sizeof(str), "[GAIN] Processed %i bytes", Utils::arrayLength(audioData));
	Logger::log(str);
	delete str;
}
