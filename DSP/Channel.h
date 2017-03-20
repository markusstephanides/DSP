#pragma once

class Channel {
public:
	Channel(const char*);
	~Channel();
	const char* getName();
private:
	// meta data
	const char* name;

	// audio data
	bool on;
	float level; // in db
	
	// processing
};