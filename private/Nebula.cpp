//
// Created by manjaca on 1/12/2024.
//

#include "../public/Nebula.h"
#include <iostream>

Nebula::Nebula(const char* texturePath, const float velocity, const int spriteWidth, const int spriteHeight)
    : Pawn(
          texturePath,
          velocity,
          spriteWidth,
          spriteHeight
      ),
      ShouldDestroy(false)

{
    InitializeCollisionVolume(50);
    std::cout << "Nebula Constructed" << std::endl;
}

Nebula::Nebula(const char* texturePath, const float posX, const float posY, const float velocity, const int spriteWidth,
               const int spriteHeight)
    : Pawn(
        texturePath,
        posX,
        posY,
        velocity,
        spriteWidth,
        spriteHeight
    )
{
    InitializeCollisionVolume(50);
    std::cout << "Nebula Constructed" << std::endl;
}

Nebula::Nebula(const float posX, const float posY)
    : Pawn(
          DefaultTexturePath,
          posX,
          posY,
          -200,
          8,
          8
      ),
      ShouldDestroy(false)
{
    InitializeCollisionVolume(50);
}

Nebula::~Nebula()
{
    std::cout << "Nebula Dedonstructed" << std::endl;
}

void Nebula::UpdateAnimation()
{
    if (RunningTime >= UpdateTime)
    {
        RunningTime = 0.0f;

        Pawn::UpdateAnimation();
    }
}

void Nebula::Tick(const float deltaTime)
{
    if (Position->x < -200)
    {
        ShouldDestroy = true;
    }

    if (!ShouldDestroy)
    {
        InitializeCollisionVolume(50);
        UpdatePositionX(deltaTime);
        Pawn::Tick(deltaTime);
    }
}

void Nebula::InitializeCollisionVolume(const float padding)
{
    ColisionVolume = new Rectangle{
        Position->x + padding,
        Position->y + padding,
        Rect->width - 2 * padding,
        Rect->height - 2 * padding,
    };
}
