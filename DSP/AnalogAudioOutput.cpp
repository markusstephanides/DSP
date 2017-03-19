#include "AnalogAudioOutput.h"
#include "AnalogAudioSystem.h"

#include <cstdio>
#include <ostream>
#include <iostream>

AnalogAudioOutput::AnalogAudioOutput(int hwIndex)
{
	this->hwIndex = hwIndex;

	this->stream = AnalogAudioSystem::openOutputStream(1);
	printf("Afer stream open!\n");
	std::cout << this->stream << std::endl;
}

//int AnalogAudioOutput::patestCallback(const void *inputBuffer, void *outputBuffer,
//	unsigned long framesPerBuffer,
//	const PaStreamCallbackTimeInfo* timeInfo,
//	PaStreamCallbackFlags statusFlags,
//	void *userData)
//{
//	float *out = static_cast<float*>(outputBuffer);
//	unsigned long i;
//
//	(void)timeInfo; /* Prevent unused variable warnings. */
//	(void)statusFlags;
//	(void)inputBuffer;
//
//
//	//for (i = 0; i < framesPerBuffer; i++)
//	//{
//	//	*out++ = data->sine[data->left_phase];  /* left */
//	//	*out++ = data->sine[data->right_phase];  /* right */
//	//	data->left_phase += 1;
//	//	if (data->left_phase >= TABLE_SIZE) data->left_phase -= TABLE_SIZE;
//	//	data->right_phase += 3; /* higher pitch so we can distinguish left and right. */
//	//	if (data->right_phase >= TABLE_SIZE) data->right_phase -= TABLE_SIZE;
//	//}
//
//	return paContinue;
//}

AnalogAudioOutput::~AnalogAudioOutput()
{
}

void AnalogAudioOutput::write(byte audioData[])
{
	printf("Write!\n");
	Pa_WriteStream(this->stream, audioData, 64);
}
