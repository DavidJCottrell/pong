#include "Opponent.hpp"

void Opponent::update(double deltaTime)
{
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