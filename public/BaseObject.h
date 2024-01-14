//
// Created by manjaca on 1/14/2024.
//

#pragma once


class BaseObject
{
public:
    virtual void Destroy();
    virtual void Tick(float deltaTime);
    virtual ~BaseObject() = default;
};
