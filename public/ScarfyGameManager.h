//
// Created by manjaca on 1/12/2024.
//

#pragma once
#include <string>
#include <vector>

class Scarfy;
class Nebula;

class ScarfyGameManager
{
public:
    static constexpr float WIN_WIDTH{512.f};
    static constexpr float WIN_HEIGHT{380.f};
    inline static const std::string WIN_TITLE{"Dasher"};

    inline static bool isFinished{false};
    inline static bool hasWon{false};

    // Acceleration due to gravity. (pixels / s) / s
    static constexpr int gravity{1000};
    static constexpr int jumpVelocity{-600};

    static void InitGame();
    static void GameFinished();
};
