#include "Utils.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;

int Utils::arrayLength(byte arr[])
{	
	return sizeof(arr) / sizeof(arr[0]);
}

long Utils::millis()
{


	auto epoch = high_resolution_clock::(0);
	// ...
	auto now = high_resolution_clock::now();

	auto mseconds = duration_cast<milliseconds>(now - epoch).count();

	std::cout << "millis: " << mseconds;
}

