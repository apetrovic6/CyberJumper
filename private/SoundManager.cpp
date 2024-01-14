//
// Created by manjaca on 1/14/2024.
//

#include "../public/SoundManager.h"
#include <iostream>

SoundManager::SoundManager(const char* soundPath, const bool playOnStart, const bool loop)
    : bIsPaused(!playOnStart)
{
    data = new Music{LoadMusicStream("../audio/soundtrack.mp3")};
    data->looping = loop;

    std::cout << "SoundManager Constructed" << std::endl;
}

void SoundManager::Play() const
{
    PlayMusicStream(*data);
}

void SoundManager::Pause() const
{
    PauseMusicStream(*data);
}

void SoundManager::Resume() const
{
    ResumeMusicStream(*data);
}

void SoundManager::UpdateStream() const
{
    UpdateMusicStream(*data);
}

void SoundManager::Stop() const
{
    StopMusicStream(*data);
}


SoundManager::~SoundManager()
{
    UnloadMusicStream(*data);

    delete data;
    std::cout << "SoundManager Deconstructed" << std::endl;
}
