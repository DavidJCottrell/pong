#ifndef ARNOLD_PLAYER_H
#define ARNOLD_PLAYER_H

#pragma once

#include <Utils.hpp>
#include <Entity.hpp>
#include <SDL2/SDL.h>
#include <thread>
#include <vector>
#include <map>

using namespace Utils::Geometry;

enum WeaponType
{
    rifle,
    shotgun,
    uzi
};

class Player final : public Entity
{
public:
    Player(const Vector2D coordinates, Game *game) : Entity(coordinates, game, 40)
    {
        dimensions = {20, 20};
    }

    void registerMovementKey(SDL_Keycode key, bool isHeld);

    void handleEvents(const SDL_Event &sdlEvent);

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;

    WeaponType weaponType = rifle;

private:
    const int healthCapacity = 40;

    const float movementSpeed = 150.0f;

    bool isCollidingWithWall(Vector2D potentialCoordinates) const;

    std::vector<SDL_Keycode> currentHeldKeys;

    std::thread uziThread;

    Vector2D mouseCoords{};

    bool mouseHeld = false;
    std::map<SDL_Keycode, bool> movementKeys = {
        {SDLK_w, false},
        {SDLK_a, false},
        {SDLK_s, false},
        {SDLK_d, false}};
};

#endif // ARNOLD_PLAYER_H
