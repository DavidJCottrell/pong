#include "Ball.hpp"

void Ball::render(SDL_Renderer *renderer)
{
    // Draw ball rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    const SDL_Rect paddleRect = {
        static_cast<int>(coordinates.x),
        static_cast<int>(coordinates.y),
        static_cast<int>(dimensions.x),
        static_cast<int>(dimensions.y)};
    SDL_RenderFillRect(renderer, &paddleRect);
}

void handleCollision(Entity *entity, const Vector2D &coordinates, const Vector2D &dimensions, float &yDirection)
{
    if (isColliding(coordinates, dimensions, entity->coordinates, entity->dimensions))
    {
        if (dynamic_cast<Player *>(entity))
        {
            yDirection = -1.0f;
        }
        else if (dynamic_cast<Opponent *>(entity))
        {
            yDirection = 1.0f;
        }
    }
}

void Ball::update(double deltaTime)
{

    if (coordinates.y <= 0 || coordinates.y + dimensions.y >= WINDOW_HEIGHT)
    {
        coordinates.x = WINDOW_WIDTH / 2;
        coordinates.y = WINDOW_HEIGHT / 2;
    }

    for (const auto &entity : game->getEntities())
    {
        if (entity)
        {
            handleCollision(entity.get(), coordinates, dimensions, yDirection);
        }
    }

    coordinates.y += static_cast<float>(yDirection * movementSpeed * deltaTime);
}
