#include "InputChannel.h"
#include <stdio.h>
#include "Logger.h"
#include "AnalogAudioOutput.h"
#include "Constants.h"
#include "VirtualDeviceHolder.h"
#include <iostream>

InputChannel::InputChannel(const char* name): Channel(name)
{

}

void InputChannel::read(byte audioData[])
{
		
}
