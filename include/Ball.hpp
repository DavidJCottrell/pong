#ifndef ARNOLD_BALL_H
#define ARNOLD_BALL_H

#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Entity.hpp"
#include "Utils.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "Opponent.hpp"

using namespace Utils::Geometry;

class Ball : public Entity
{
public:
    Ball(const Vector2D coordinates, Game *game, const Vector2D dimensions, const float movementSpeed)
        : Entity(coordinates, game, 40), movementSpeed(movementSpeed)
    {
        this->dimensions = dimensions;
    }

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;

    float xDirection = 0.0f;

private:
    float yDirection = 1.0f;

    float getBounceAngle(const Vector2D &entityCoordinates, const Vector2D &entityDimensions);
    void handleCollision(Entity *entity);

protected:
    const float movementSpeed;
};

#endif // ARNOLD_BALL_H