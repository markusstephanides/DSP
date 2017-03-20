#pragma once

class Constants
{
public:
	const static int AUDIO_BUFFER_SIZE = 1920; // The best buffer for 48000khz and 4 byte frames according to WASAPI
	const static int NET_BUFFER_SIZE = AUDIO_BUFFER_SIZE + 2; // Because the packet id and the channel id are also sent with the audio data
};
