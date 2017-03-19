#include "Utils.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;

int Utils::arrayLength(byte arr[])
{	
	return sizeof(arr) / sizeof(arr[0]);
}

