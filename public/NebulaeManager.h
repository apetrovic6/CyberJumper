//
// Created by manjaca on 1/13/2024.
//

#pragma once
#include <vector>
#include "BaseObject.h"

class Nebula;

class NebulaeManager final : public BaseObject
{
public:
    explicit NebulaeManager(int numberOfNebulae = 6);

    ~NebulaeManager() override;

    void Tick(float deltaTime) const;
    bool CheckIfNebulaeIsEmpty() const;

private:
    std::vector<Nebula*>* nebulae;

public:
    std::vector<Nebula*>* GetNebulae() const { return nebulae; };
};
