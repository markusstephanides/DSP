#include "Channel.h"
#include <iostream>

Channel::Channel(): name(nullptr), on(false), level(0)
{
}

Channel::~Channel() {
	delete this->name;
}
