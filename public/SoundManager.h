//
// Created by manjaca on 1/14/2024.
//

#pragma once

#include <raylib.h>

#include "BaseObject.h"

class SoundManager final : public BaseObject
{
public:
    SoundManager(const char* soundPath, bool playOnStart = false ,bool loop = false);
    ~SoundManager() override;

    void Play() const;
    void Pause() const;
    void Resume() const;
    void UpdateStream() const;
    void Stop() const;

private:
    Music* data;
    bool bIsPaused;

};
