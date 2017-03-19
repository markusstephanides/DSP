#include "AnalogAudioSystem.h"
#include <cstdio>
#include "Logger.h"

void AnalogAudioSystem::init()
{
	//Initialize
	PaError err = Pa_Initialize();
	if (err != paNoError)
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return;
	}

	// List available devices
	int numDevices;
	numDevices = Pa_GetDeviceCount();
	if (numDevices < 0)
	{
		printf("ERROR: Pa_CountDevices returned 0x%x\n", numDevices);
		return;
	}

	const PaDeviceInfo *deviceInfo;
	for (int i = 0; i < numDevices; i++)
	{
		deviceInfo = Pa_GetDeviceInfo(i);
		printf("Device Name: %s\n", deviceInfo->name);
	}


}

void AnalogAudioSystem::shutdown()
{
	Logger::log("SHUTDOWN!");
	PaError err = Pa_Terminate();
	if (err != paNoError)
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
}
