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
	case SoundPlayer::C4:
		fullAudioFilePath += "C4.wav";
		break;
	case SoundPlayer::D4:
		fullAudioFilePath += "D4.wav";
		break;
	case SoundPlayer::E4:
		fullAudioFilePath += "E4.wav";
		break;
	case SoundPlayer::F4:
		fullAudioFilePath += "F4.wav";
		break;
	case SoundPlayer::G4:
		fullAudioFilePath += "G4.wav";
		break;
	case SoundPlayer::A4:
		fullAudioFilePath += "A4.wav";
		break;
	case SoundPlayer::B4:
		fullAudioFilePath += "B4.wav";
		break;
	case SoundPlayer::C5:
		fullAudioFilePath += "C5.wav";
		break;
	default:
		break;
	}

	return fullAudioFilePath;
}
