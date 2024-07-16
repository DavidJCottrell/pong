#include "Paddle.hpp"

void Paddle::render(SDL_Renderer *renderer)
{
    // Draw paddle rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    const SDL_Rect paddleRect = {
        static_cast<int>(coordinates.x),
        static_cast<int>(coordinates.y),
        static_cast<int>(dimensions.x),
        static_cast<int>(dimensions.y)};
    SDL_RenderFillRect(renderer, &paddleRect);
}

void Paddle::update(double deltaTime)
{
    // Implementation for update will be in derived classes
}