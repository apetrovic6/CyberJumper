//
// Created by manjaca on 1/14/2024.
//

#include "../public/BackgroundManager.h"

#include <iostream>

BackgroundManager::BackgroundManager()
    : backgroundX(0),
      midgroundX(0),
      foregroundX(0)
{
    background = new Texture2D(LoadTexture(DefaultBackgroundPath));
    midground = new Texture2D(LoadTexture(DefaultMidgroundPath));
    foreground = new Texture2D(LoadTexture(DefaultForegroundPath));

    std::cout << "Background Manager Constructed" << std::endl;
}


void BackgroundManager::Tick(const float deltaTime)
{
    Draw(deltaTime);
    BaseObject::Tick(deltaTime);
}

void BackgroundManager::Draw(const float deltaTime)
{
    UpdateX(deltaTime);

    DrawTextureEx(*background, {backgroundX, 0}, 0.0, 2.0, WHITE);
    DrawTextureEx(*background, {backgroundX + static_cast<float>(background->width) * 2, 0}, 0.0, 2.0, WHITE);

    DrawTextureEx(*midground, {midgroundX, 0}, 0.0, 2.0, WHITE);
    DrawTextureEx(*midground, {midgroundX + static_cast<float>(midground->width) * 2, 0}, 0.0, 2.0, WHITE);

    DrawTextureEx(*foreground, {foregroundX, 0}, 0.0, 2.0, WHITE);
    DrawTextureEx(*foreground, {foregroundX + static_cast<float>(foreground->width) * 2, 0}, 0.0, 2.0, WHITE);
}

void BackgroundManager::UpdateX(const float deltaTime)
{
    backgroundX -= 20 * deltaTime;
    midgroundX -= 40 * deltaTime;
    foregroundX -= 80 * deltaTime;

    if (backgroundX <= static_cast<float>(-background->width) * 2)
    {
        backgroundX = 0.0f;
    }

    if (midgroundX <= static_cast<float>(-midground->width) * 2)
    {
        midgroundX = 0.0f;
    }

    if (foregroundX <= static_cast<float>(-foreground->width) * 2)
    {
        foregroundX = 0.0f;
    }
}

BackgroundManager::~BackgroundManager()
{
    UnloadTexture(*background);
    UnloadTexture(*midground);
    UnloadTexture(*foreground);

    delete background;
    delete midground;
    delete foreground;

    std::cout << "Background Manager Deconstructed" << std::endl;
}
