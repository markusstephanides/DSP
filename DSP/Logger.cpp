#include "Logger.h"
#include <cstdio>
#include <cstdarg>

void Logger::log(const char* string)
{
	printf(string);
	printf("\n");
}
