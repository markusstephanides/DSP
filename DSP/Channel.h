#pragma once

class Channel {
public:
	Channel();
	~Channel();
private:
	// meta data
	char* name;
	// audio data
	bool on;
	float level; // in db
	
	 
};