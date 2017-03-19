﻿#include "AnalogAudioSystem.h"
#include <cstdio>
#include "Logger.h"
#include <string>

#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER (64)

std::list<PaStream*> openStreams = std::list<PaStream*>();

void AnalogAudioSystem::init()
{
	//Initialize
	PaError err = Pa_Initialize();
	if (err != paNoError)
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return;
	}
}

PaStream* AnalogAudioSystem::openOutputStream(int hwIndex, PaStreamCallback *callback, void* context)
{
	// List available devices
	int numDevices;
	numDevices = Pa_GetDeviceCount();
	if (numDevices < 0)
	{
		printf("ERROR: Pa_CountDevices returned 0x%x\n", numDevices);
		return nullptr;
	}

	const PaDeviceInfo *deviceInfo;
	int deviceIndex = -1;
	for (int i = 0; i < numDevices; i++)
	{
		deviceInfo = Pa_GetDeviceInfo(i);
		std::string deviceName = std::string(deviceInfo->name);
		if (deviceName.find("USB Audio Device: - (hw:") != std::string::npos)
		{
			std::string index = deviceName.substr(24, 1);
			int devIndex = stoi(index);
			if (devIndex == hwIndex)
			{
				deviceIndex = i;
				printf("Found target output device with hwIndex %i and deviceIndex %i!\n", devIndex, deviceIndex);
			}
		}

		printf("Device Name: %s\n", deviceInfo->name);
	}

	PaStreamParameters outputParameters;
	PaStream *stream;
	PaError err;

	outputParameters.device = deviceIndex;
	outputParameters.channelCount = 2;       /* stereo output */
	outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
	outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = nullptr;

	printf("LOW OUTPUT LATENCY: %f", outputParameters.suggestedLatency);

	err = Pa_OpenStream(
		&stream,
		nullptr, /* no input */
		&outputParameters,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paClipOff,      /* we won't output out of range samples so don't bother clipping them */
		callback,
		context);

	if (err != paNoError)
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return nullptr;
	}

	Pa_StartStream(stream);

	return stream;

}

void AnalogAudioSystem::shutdown()
{
	PaError err;

	// close all open streams
	for (auto stream : openStreams)
	{
		err = Pa_StopStream(stream);
		if (err != paNoError)
		{
			printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		}

		err = Pa_CloseStream(stream);
		if (err != paNoError)
		{
			printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		}
	}

	err = Pa_Terminate();
	if (err != paNoError)
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
}
