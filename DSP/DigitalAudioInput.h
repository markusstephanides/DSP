#pragma once
#include "AudioInput.h"

class DigitalAudioInput : public AudioInput
{
public:
	explicit DigitalAudioInput(int);
	virtual ~DigitalAudioInput();
	int getInputId() const;
	void read(byte[]);
	//void setInputId(int);
private:
	int inputId;


};
