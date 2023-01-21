#include "SoundPlayer.h"

SoundPlayer::SoundPlayer()
{
}

void SoundPlayer::play(SoundName soundName)
{
	if (!this->buffer.loadFromFile(getAudioFileName(soundName)))
		std::cout << "error loading the audio";

	sound.setBuffer(this->buffer);
	sound.play();
}

String SoundPlayer::getAudioFileName(SoundName soundName)
{
	String fullAudioFilePath = audioFilesPath;

	switch (soundName)
	{
	case SoundPlayer::Ejemplo1:
		fullAudioFilePath += "ejemplo1.wav";
		break;
	case SoundPlayer::Ejemplo2:
		fullAudioFilePath += "ejemplo2.wav";
		break;
	default:
		break;
	}

	return fullAudioFilePath;
}
