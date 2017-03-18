#include "Channel.h"
#include <iostream>

Channel::Channel() {
	
}

Channel::~Channel() {
	delete this->name;
}