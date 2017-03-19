#include "AudioOutput.h"

AudioOutput::~AudioOutput()
{
	delete this->name;
}
