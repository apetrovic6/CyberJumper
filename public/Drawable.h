//
// Created by manjaca on 1/14/2024.
//

#pragma once
#include <raylib.h>

#include "BaseObject.h"


class Drawable : public BaseObject
{
public:
	Drawable(const char* texturePath, float posX, float posY, int spriteWidth, int spriteHeight);
	Drawable(const char* texturePath, int spriteWidth, int spriteHeight);
	~Drawable() override;

	void Tick(float deltaTime) override;

	virtual void Draw();

protected:
	Texture2D* Texture;
	Rectangle* Rect;
	Vector2* Position;
	Rectangle* ColisionVolume;
	int SpriteWidth;
	int SpriteHeight;

	virtual void InitializeCollisionVolume(float padding);

public:
	Rectangle* GetRect() const { return Rect; }
	Rectangle* GetColisionVolume() const { return ColisionVolume; }
};
