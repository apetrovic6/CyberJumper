//
// Created by manjaca on 1/14/2024.
//

#include "../public/Drawable.h"

#include <iostream>

#include "../public/ScarfyGameManager.h"

Drawable::Drawable(const char* texturePath, const float posX, const float posY, const int spriteWidth,
                   const int spriteHeight)
    :
    SpriteWidth(spriteWidth),
    SpriteHeight(spriteHeight)
{
    Texture = new Texture2D(LoadTexture(texturePath));

    Rect = new Rectangle{
        0, 0, static_cast<float>(Texture->width) / static_cast<float>(spriteWidth),
        static_cast<float>(Texture->height) / static_cast<float>(spriteHeight)
    };

    Position = new Vector2{posX, posY};

    std::cout << "Drawable Constructed" << std::endl;
}

Drawable::Drawable(const char* texturePath, const int spriteWidth, const int spriteHeight)
    :
    SpriteWidth(spriteWidth),
    SpriteHeight(spriteHeight)
{
    Texture = new Texture2D(LoadTexture(texturePath));

    Rect = new Rectangle{
        0, 0, static_cast<float>(Texture->width) / static_cast<float>(spriteWidth),
        static_cast<float>(Texture->height) / static_cast<float>(spriteHeight)
    };

    Position = new Vector2{
        ScarfyGameManager::WIN_WIDTH / 2.f - Rect->width / 2.f, ScarfyGameManager::WIN_HEIGHT - Rect->height
    };

    std::cout << "Drawable Constructed" << std::endl;
}

void Drawable::Draw()
{
    DrawTextureRec(*Texture, *Rect, *Position, WHITE);
}

 void Drawable::InitializeCollisionVolume(float padding)
{

}

Drawable::~Drawable()
{
    UnloadTexture(*Texture);

    delete Texture;
    delete Rect;
    delete Position;
    delete ColisionVolume;

    std::cout << "Drawable Deconstructed" << std::endl;
}

void Drawable::Tick(const float deltaTime)
{
}



