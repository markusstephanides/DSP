#pragma once
#include "Utils.h"

class Plugin
{
public:
	Plugin();
	~Plugin();
	virtual void process(byte[]);
};
