#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class SoundPlayer
{
public:
	SoundPlayer();
	enum SoundName {
		Ejemplo1,
		Ejemplo2
	};
	void play(SoundName soundName);

private:
	SoundBuffer buffer;
	Sound sound;

	String audioFilesPath = "assets/audio/";

	String getAudioFileName(SoundName soundName);


};

