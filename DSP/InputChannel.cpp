﻿#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"

InputChannel::InputChannel(const char* name): Channel(name)
{
	output_ = new AnalogAudioOutput(1, "DX2000");
}

void InputChannel::read(byte audioData[])
{
	int sum = 0;

	for (int i = 0; i < Utils::arrayLength(audioData); i++)
	{
		sum += audioData[i];
	}

	printf("Length: %i - Sum::: %i\n", Utils::arrayLength(audioData), sum);
	output_->write(audioData);

}
