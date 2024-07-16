#include "Player.hpp"

void Player::registerMovementKey(const SDL_Keycode key, const bool isHeld)
{
    auto const movementKey = movementKeys.find(key);
    if (movementKey != movementKeys.end())
        movementKey->second = isHeld;
}

void Player::handleEvents(const SDL_Event &sdlEvent)
{
    switch (sdlEvent.type)
    {
    case SDL_KEYDOWN:
        registerMovementKey(sdlEvent.key.keysym.sym, true);
        break;
    case SDL_KEYUP:
        registerMovementKey(sdlEvent.key.keysym.sym, false);
        break;
    default:
        break;
    }
}

void Player::render(SDL_Renderer *renderer)
{
    // Draw player rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    const SDL_Rect playerRect = {
        static_cast<int>(coordinates.x),
        static_cast<int>(coordinates.y),
        static_cast<int>(dimensions.x),
        static_cast<int>(dimensions.y)};
    SDL_RenderFillRect(renderer, &playerRect);
}

void Player::update(const double deltaTime)
{
    Vector2D moveAmount = {0.0f, 0.0f};

    for (auto &[key, held] : movementKeys)
    {
        if (held)
        {
            switch (key)
            {
            case SDLK_a:
                moveAmount.x -= 1.0f;
                break;
            case SDLK_d:
                moveAmount.x += 1.0f;
                break;
            default:
                break;
            }
        }
    }

    moveAmount = normalise(moveAmount);

    coordinates.x += static_cast<float>(moveAmount.x * movementSpeed * deltaTime);
}
