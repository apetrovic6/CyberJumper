//
// Created by manjaca on 1/13/2024.
//

#include "../public/NebulaeManager.h"
#include "../public/Nebula.h"
#include "../public/ScarfyGameManager.h"
#include <iostream>
#include <random>

NebulaeManager::NebulaeManager(const int numberOfNebulae)
{
    nebulae = new std::vector<Nebula*>(numberOfNebulae);

    for (int i = 0; i < numberOfNebulae; i++)
    {
        nebulae->at(i) = new Nebula(
            ScarfyGameManager::WIN_WIDTH + 300.f * static_cast<float>(i),
            ScarfyGameManager::WIN_HEIGHT - 100.0
        );
    }

    std::cout << "NebulaeManager Constructed" << std::endl;
}


void NebulaeManager::Tick(const float deltaTime) const
{
    for (size_t i = 0; i < nebulae->size(); i++)
    {
        if (nebulae->at(i) == nullptr)
        {
            const auto it = std::next(nebulae->begin(), i);
            nebulae->erase(it);

            continue;
        }

        if (!nebulae->at(i)->GetShouldDestroy())
        {
            nebulae->at(i)->Tick(deltaTime);
        }
        else
        {
            nebulae->at(i)->Destroy();
            nebulae->at(i) = nullptr;
        }
    }

    if (CheckIfNebulaeIsEmpty())
    {
        ScarfyGameManager::isFinished = true;
        ScarfyGameManager::hasWon = true;
    }
}

bool NebulaeManager::CheckIfNebulaeIsEmpty() const
{
    return nebulae->empty();
}

NebulaeManager::~NebulaeManager()
{
    for (const Nebula* nebula : *nebulae)
    {
        delete nebula;
    }

    delete nebulae;
    std::cout << "NebulaeManager Deconstructed" << std::endl;
}
