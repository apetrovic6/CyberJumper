//
// Created by manjaca on 1/14/2024.
//

#pragma once

#include "BaseObject.h"
#include "Raylib.h"

class BackgroundManager final : public BaseObject
{
public:
    BackgroundManager();
    ~BackgroundManager() override;
    void Tick(float deltaTime) override;

private:
    Texture2D* background;
    Texture2D* midground;
    Texture2D* foreground;

    float backgroundX;
    float midgroundX;
    float foregroundX;

    void Draw(float deltaTime);
    void UpdateX(float deltaTime);

    const char* DefaultBackgroundPath = "../textures/far-buildings.png";
    const char* DefaultMidgroundPath = "../textures/back-buildings.png";
    const char* DefaultForegroundPath = "../textures/foreground.png";
};
