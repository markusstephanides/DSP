#pragma once

class Channel {
public:
	Channel(const char*);
	~Channel();
private:
	// meta data
	const char* name;

	// audio data
	bool on;
	float level; // in db
	
	// processing
};