/*
 * Xournal++
 *
 * Class to play audio from a MP3-file
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

#include "AudioQueue.h"
#include "PortAudioConsumer.h"
#include "VorbisProducer.h"

#include <control/settings/Settings.h>

class AudioPlayer
{
public:
	explicit AudioPlayer(Control* control, Settings* settings);
	~AudioPlayer();
	bool start(string filename, unsigned int timestamp = 0);
	bool isPlaying();
	void stop();
	bool play();
	void pause();

	vector<DeviceInfo> getOutputDevices();

private:
	XOJ_TYPE_ATTRIB;

protected:
	Settings* settings = nullptr;
	Control* control = nullptr;

	AudioQueue<int>* audioQueue = nullptr;
	PortAudioConsumer* portAudioConsumer = nullptr;
	VorbisProducer* vorbisProducer = nullptr;
	std::thread stopThread;
};
