#pragma once
#include "Utils.h"

class Plugin
{
public:
	Plugin();
	virtual ~Plugin();
	virtual void process(byte[]);
};
