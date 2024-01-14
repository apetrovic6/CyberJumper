//
// Created by manjaca on 1/14/2024.
//

#include "../public/BaseObject.h"

void BaseObject::Destroy()
{
    delete this;
}

void BaseObject::Tick(float deltaTime)
{
}

