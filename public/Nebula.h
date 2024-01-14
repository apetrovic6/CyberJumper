//
// Created by manjaca on 1/12/2024.
//

#pragma once
#include "Pawn.h"


class Nebula final : public Pawn
{
public:
    explicit Nebula(const char* texturePath, float velocity, int spriteWidth, int spriteHeight);

    explicit Nebula(const char* texturePath, float posX, float posY, float velocity, int spriteWidth, int spriteHeight);

    explicit Nebula(float posX, float posY);

    inline static const char* DefaultTexturePath = "../textures/12_nebula_spritesheet.png";

    ~Nebula() override;

    void UpdateAnimation() override;

    void Tick(float deltaTime) override;

private:
    bool ShouldDestroy;

protected:
    void InitializeCollisionVolume(float padding) override;

public:
    bool GetShouldDestroy() const { return ShouldDestroy; }
};


