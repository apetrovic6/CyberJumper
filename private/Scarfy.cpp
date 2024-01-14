//
// Created by manjaca on 1/12/2024.
//

#include "../public/Scarfy.h"
#include "../public/ScarfyGameManager.h"
#include <iostream>


Scarfy::Scarfy(const char* texturePath, const float velocity, const int spriteWidth, const int spriteHeight)
    : Pawn(
        texturePath,
        velocity,
        spriteWidth,
        spriteHeight
    )
{
    InitializeCollisionVolume(0);
    jumpSound = new Sound{LoadSound(DefaultJumpSoundPath)};
    DeathSound = new Sound{LoadSound(DefaultDeathSoundPath)};
    std::cout << "Scarfy Constructed" << std::endl;
}

Scarfy::Scarfy(const char* texturePath, const int spriteWidth, const int spriteHeight): Pawn(
    texturePath,
    velocity = 0,
    spriteWidth,
    spriteHeight
)
{
    InitializeCollisionVolume(0);
    jumpSound = new Sound{LoadSound(DefaultJumpSoundPath)};
    DeathSound = new Sound{LoadSound(DefaultDeathSoundPath)};
    std::cout << "Scarfy Constructed" << std::endl;
}

Scarfy::Scarfy(const int spriteWidth, const int spriteHeight) : Pawn(
    DefaultTexturePath,
    spriteWidth,
    spriteHeight
)
{
    InitializeCollisionVolume(0);
    jumpSound = new Sound{LoadSound(DefaultJumpSoundPath)};
    DeathSound = new Sound{LoadSound(DefaultDeathSoundPath)};
    std::cout << "Scarfy Constructed" << std::endl;
}

void Scarfy::Jump()
{
    PlaySound(*jumpSound);
    velocity += ScarfyGameManager::jumpVelocity;
}

void Scarfy::UpdateAnimation()
{
    if (RunningTime >= UpdateTime)
    {
        RunningTime = 0.0f;

        if (!bIsInAir)
        {
            Pawn::UpdateAnimation();
        }
    }
}

bool Scarfy::IsOnGround() const
{
    return Position->y >= ScarfyGameManager::WIN_HEIGHT - GetRect()->height;
}

void Scarfy::InitializeCollisionVolume(float padding)
{
    ColisionVolume = new Rectangle{
        Position->x,
        Position->y,
        Rect->width,
        Rect->height,
    };
}

void Scarfy::CheckIfOnGround(const float deltaTime)
{
    if (IsOnGround())
    {
        // scarfy is on the ground
        SetVelocityToZero();
        SetIsInAir(false);
    }
    else
    {
        // scarfy is in the air
        AddVelocity(deltaTime);
        SetIsInAir(true);
    }

    // Check for Jumping
    if (ShouldJump())
    {
        Jump();
    }
}

void Scarfy::Tick(const float deltaTime)
{
    InitializeCollisionVolume(0);
    CheckIfOnGround(deltaTime);
    UpdatePositionY(deltaTime);
    Pawn::Tick(deltaTime);
}

void Scarfy::PlayDeathSound() const
{
    PlaySound(*DeathSound);
}

Scarfy::~Scarfy()
{
    UnloadSound(*jumpSound);
    UnloadSound(*DeathSound);

    delete jumpSound;
    delete DeathSound;

    std::cout << "Scarfy Deonstructed" << std::endl;
}
