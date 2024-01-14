//
// Created by manjaca on 1/12/2024.
//

#pragma once

#include "Drawable.h"

class Pawn : public Drawable
{
public:
	explicit Pawn(const char* texturePath, float velocity, int spriteWidth, int spriteHeight);

	explicit Pawn(const char* texturePath, float posX, float posY, float velocity, int spriteWidth,
	              int spriteHeight);

	explicit Pawn(const char* texturePath, int spriteWidth, int spriteHeight);

	~Pawn() override;


	void AddVelocity(float deltaTime);

	void UpdatePositionY(float deltaTime) const;

	void UpdatePositionX(float deltaTime) const;

	bool CheckForCollision(const Pawn* pawn) const;
	virtual void UpdateAnimation();

	void Tick(float deltaTime) override;

private:

protected:
	float velocity{};
	float UpdateTime{1.0 / 12.0};
	float RunningTime{};
	int frame{};

	void SetAnimationFrame() const;

public:
	void IncrementCurrentFrame() { frame++; };
	void SetCurrentFrame(const int newFrame) { frame = newFrame; };
	[[nodiscard]] int GetCurrentFrame() const { return frame; };
	[[nodiscard]] float GetRunningTime() const { return RunningTime; };
	void AddRunningTime(const float newRunningTime) { RunningTime += newRunningTime; };
};
