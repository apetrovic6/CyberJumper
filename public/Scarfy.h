//
// Created by manjaca on 1/12/2024.
//

#pragma once

#include "Pawn.h"

class Scarfy final : public Pawn
{
public:
    explicit Scarfy(const char* texturePath, float velocity, int spriteWidth, int spriteHeight);
    explicit Scarfy(const char* texturePath, int spriteWidth, int spriteHeight);
    explicit Scarfy(int spriteWidth, int spriteHeight);

    void Jump();
    void UpdateAnimation() override;
    void CheckIfOnGround(float deltaTime);
    void Tick(float deltaTime) override;
    void PlayDeathSound() const;
    bool IsOnGround() const;

private:
    bool bIsInAir{false};
    Sound* jumpSound;
    Sound* DeathSound;

protected:
    void InitializeCollisionVolume(float padding) override;

public:
    Texture2D* GetTexture() const { return Texture; }
    Vector2* GetPosition() const { return Position; }
    void SetIsInAir(const bool inAir) { bIsInAir = inAir; };
    void SetVelocityToZero() { velocity = 0; };
    bool ShouldJump() const { return IsKeyPressed(KEY_SPACE) && !bIsInAir; };
    bool GetIsInAir() const { return bIsInAir; };
    float GetVelocity() const { return velocity; };
    float GetUpdateTime() const { return UpdateTime; };

    inline static const char* DefaultTexturePath = "../textures/scarfy.png";
    inline static const char* DefaultJumpSoundPath = "../audio/sfx_jump.mp3";
    inline static const char* DefaultDeathSoundPath = "../audio/sfx_explosion.mp3";

    ~Scarfy() override;
};
