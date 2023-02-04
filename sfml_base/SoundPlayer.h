#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class SoundPlayer
{
public:
	SoundPlayer();
	enum SoundName {
		C4,
		D4,
		E4,
		F4,
		G4,
		A4,
		B4,
		C5,
		MISS
	};
	void play(SoundName soundName);

private:
	SoundBuffer buffer;
	Sound sound;

	String audioFilesPath = "assets/audio/";

	String getAudioFileName(SoundName soundName);


};

