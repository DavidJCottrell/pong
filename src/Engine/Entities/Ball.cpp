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

float Ball::getBounceAngle(const Vector2D &entityCoordinates, const Vector2D &entityDimensions)
{
    return atan2((entityCoordinates.y + entityDimensions.y / 2) - (coordinates.y + dimensions.y / 2),
                 (entityCoordinates.x + entityDimensions.x / 2) - (coordinates.x + dimensions.x / 2));
}

void Ball::handleCollision(Entity *entity)
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
        xDirection = getBounceAngle(entity->coordinates, entity->dimensions);
    }
}

void Ball::update(double deltaTime)
{

    Vector2D moveAmount = {0.0f, 0.0f};

    // Bounce ball off the window edges
    if (coordinates.x <= 0 || coordinates.x + dimensions.x >= WINDOW_WIDTH)
    {
        xDirection = xDirection * -1.0f;
    }

    if (coordinates.y <= 0 || coordinates.y + dimensions.y >= WINDOW_HEIGHT)
    {
        // Player scored
        if (coordinates.y <= 0)
        {
            game->score++;
        }
        // Reset ball position
        yDirection = 1.0f;
        xDirection = 0.0f;
        coordinates.x = WINDOW_WIDTH / 2;
        coordinates.y = 100;
    }

    for (const auto &entity : game->getEntities())
    {
        if (entity)
        {
            if (dynamic_cast<Paddle *>(entity.get()))
            {
                handleCollision(entity.get());
            }
        }
    }

    moveAmount.x = xDirection;
    moveAmount.y = yDirection;

    moveAmount = normalise(moveAmount);

    coordinates.x += static_cast<float>(moveAmount.x * movementSpeed * deltaTime);
    coordinates.y += static_cast<float>(moveAmount.y * movementSpeed * deltaTime);
}
