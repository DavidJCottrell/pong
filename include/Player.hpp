#ifndef ARNOLD_PLAYER_H
#define ARNOLD_PLAYER_H

#pragma once

#include <Paddle.hpp>
#include <SDL2/SDL.h>
#include <thread>
#include <vector>
#include <map>

class Player final : public Paddle
{
public:
    Player(const Vector2D coordinates, Game *game)
        : Paddle(coordinates, game, {50, 5}, 150.0f) {}

    void registerMovementKey(SDL_Keycode key, bool isHeld);

    void handleEvents(const SDL_Event &sdlEvent);

    void update(double deltaTime) override;

private:
    std::vector<SDL_Keycode> currentHeldKeys;
    std::map<SDL_Keycode, bool> movementKeys = {
        {SDLK_a, false},
        {SDLK_d, false},
    };
};

#endif // ARNOLD_PLAYER_H