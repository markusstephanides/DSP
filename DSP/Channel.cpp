#include "Channel.h"
#include <iostream>

Channel::Channel(const char* name): name(name), on(false), level(0)
{
}

Channel::~Channel() {
	
}
