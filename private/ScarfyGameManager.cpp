//
// Created by manjaca on 1/12/2024.
//

#include "../public/ScarfyGameManager.h"
#include <raylib.h>
#include <iostream>

void ScarfyGameManager::InitGame()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE.data());
    SetTargetFPS(60);
    InitAudioDevice();
}

void ScarfyGameManager::GameFinished()
{
    if (hasWon)
    {
        DrawText("You Won!", ScarfyGameManager::WIN_WIDTH / 3.5f, ScarfyGameManager::WIN_HEIGHT / 2.f, 40,
                 GREEN);
    }
    else
    {
        DrawText("Game Over!", ScarfyGameManager::WIN_WIDTH / 3.5f, ScarfyGameManager::WIN_HEIGHT / 2.f, 40,
                 RED);
    }
    EndDrawing();
}
