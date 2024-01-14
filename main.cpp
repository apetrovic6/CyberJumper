#include <iostream>
#include <vector>
#include "raylib.h"
#include "string"
#include "public/BackgroundManager.h"
#include "public/Nebula.h"
#include "public/NebulaeManager.h"
#include "public/ScarfyGameManager.h"
#include "public/Scarfy.h"
#include "public/SoundManager.h"

int main()
{
    ScarfyGameManager::InitGame();

    const auto scarfy = new Scarfy(6, 1);
    const auto nebulaeManager = new NebulaeManager(10);
    const auto backgroundManager = new BackgroundManager();

    const auto soundtrack = new SoundManager("../audio/soundtrack.mp3", true, true);

    soundtrack->Play();

    while (!WindowShouldClose())
    {
        const float deltaTime{GetFrameTime()};
        soundtrack->UpdateStream();
        BeginDrawing();
        ClearBackground(WHITE);

        if (!ScarfyGameManager::isFinished)
        {
            backgroundManager->Tick(deltaTime);
            nebulaeManager->Tick(deltaTime);
            scarfy->Tick(deltaTime);
        }
        else
        {
            ScarfyGameManager::GameFinished();
            soundtrack->Stop();
            continue;
        }

        for (const Nebula* Nebula : *(nebulaeManager->GetNebulae()))
        {
            if (Nebula != nullptr)
            {
                if (scarfy->CheckForCollision(Nebula))
                {
                    scarfy->PlayDeathSound();
                    ScarfyGameManager::isFinished = true;
                    ScarfyGameManager::hasWon = false;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    nebulaeManager->Destroy();
    scarfy->Destroy();
    backgroundManager->Destroy();
    soundtrack->Destroy();

    return 0;
}
