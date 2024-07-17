#include "Opponent.hpp"

void Opponent::update(double deltaTime)
{
    // TODO: This is also wonky

    for (const auto &entity : game->getEntities())
    {
        if (entity)
        {
            if (Ball *ball = dynamic_cast<Ball *>(entity.get()))
            {
                Vector2D moveAmount = {ball->xDirection, 0.0f};
                moveAmount = normalise(moveAmount);
                xDirection = moveAmount.x;
            }
        }
    }

    // Change direction when the paddle hits the borders
    if (coordinates.x + dimensions.x >= WINDOW_WIDTH)
    {
        xDirection = -1.0f;
    }
    else if (coordinates.x < 0)
    {
        xDirection = 1.0f;
    }

    coordinates.x += static_cast<float>(xDirection * movementSpeed * deltaTime);
}