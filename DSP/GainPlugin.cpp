#include "GainPlugin.h"
#include "Logger.h"
#include <cstdio>

void GainPlugin::process(byte audioData[])
{
	const char* str = "";
	sprintf_s(str, sizeof(str), "[GAIN] Processed %i bytes", Utils::arrayLength(audioData));
	Logger::log(str);
}
