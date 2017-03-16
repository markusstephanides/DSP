#include "Logger.h"
#include <cstdio>

void Logger::log(const char* string)
{
	printf(string);
	printf("\n");
}
