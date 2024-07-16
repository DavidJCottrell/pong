#ifndef ARNOLD_OPPONENT_H
#define ARNOLD_OPPONENT_H

#pragma once

#include <SDL2/SDL.h>
#include <thread>
#include <vector>
#include <map>
#include "Paddle.hpp"
#include "Constants.hpp"

class Opponent final : public Paddle
{
public:
    Opponent(const Vector2D coordinates, Game *game)
        : Paddle(coordinates, game, {100, 5}, 100.0f) {}

    void update(double deltaTime) override;

private:
    float xDirection = 1;
};

#endif // ARNOLD_OPPONENT_H