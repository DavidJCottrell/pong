#ifndef ARNOLD_PADDLE_H
#define ARNOLD_PADDLE_H

#pragma once

#include <Utils.hpp>
#include <SDL2/SDL.h>

#include "Entity.hpp"

using namespace Utils::Geometry;

class Paddle : public Entity
{
public:
    Paddle(const Vector2D coordinates, Game *game, const Vector2D dimensions, const float movementSpeed)
        : Entity(coordinates, game, 40), movementSpeed(movementSpeed)
    {
        this->dimensions = dimensions;
    }

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;

protected:
    const float movementSpeed;
};

#endif // ARNOLD_PADDLE_H