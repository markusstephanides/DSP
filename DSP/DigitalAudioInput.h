#pragma once
#include "AudioInput.h"

class DigitalAudioInput : public AudioInput
{
public:
	explicit DigitalAudioInput(int, const char*);
	virtual ~DigitalAudioInput();
	byte getInputId() const;
	void read(byte[]) override;
	//void setInputId(int);
private:
	byte inputId;


};
