//
// Created by manjaca on 1/12/2024.
//

#include <iostream>
#include "../public/Pawn.h"
#include "../public/ScarfyGameManager.h"

Pawn::Pawn(const char* texturePath, const float velocity, const int spriteWidth, const int spriteHeight)
    :
    Drawable(texturePath, 0, 0, spriteWidth, spriteHeight),
    velocity(velocity)
{
    std::cout << "Pawn Constructed" << std::endl;
}

Pawn::Pawn(const char* texturePath, const float posX, const float posY, const float velocity,
           const int spriteWidth,
           const int spriteHeight)
    :
    Drawable(texturePath, posX, posY, spriteWidth, spriteHeight),
    velocity(velocity)

{
    std::cout << "Pawn Constructed" << std::endl;
}

Pawn::Pawn(const char* texturePath, const int spriteWidth, const int spriteHeight)
    : Drawable(texturePath, spriteWidth, spriteHeight)
{
    std::cout << "Pawn Constructed" << std::endl;
}

void Pawn::AddVelocity(const float deltaTime)
{
    velocity += ScarfyGameManager::gravity * deltaTime;
}

void Pawn::UpdatePositionY(const float deltaTime) const
{
    Position->y += velocity * deltaTime;
}

void Pawn::UpdatePositionX(const float deltaTime) const
{
    Position->x += velocity * deltaTime;
}

bool Pawn::CheckForCollision(const Pawn* pawn) const
{
    if (CheckCollisionRecs(*(pawn->GetColisionVolume()), *ColisionVolume))
    {
        return true;
    }

    return false;
}

void Pawn::SetAnimationFrame() const
{
    Rect->x = static_cast<float>(frame) * Rect->width;
}

void Pawn::UpdateAnimation()
{
    SetAnimationFrame();
    IncrementCurrentFrame();
    if (frame > SpriteWidth - 1)
    {
        frame = 0;
    }
}


void Pawn::Tick(const float deltaTime)
{
    AddRunningTime(deltaTime);
    UpdateAnimation();
    Draw();
}

Pawn::~Pawn()
{
    std::cout << "Pawn Deonstructed" << std::endl;
}
