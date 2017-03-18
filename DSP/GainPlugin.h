#pragma once
#include "Plugin.h"

class GainPlugin : public Plugin
{
public:
	void process(byte[]) override;
private:
	float amplifier;
};
