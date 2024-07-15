#ifndef ARNOLD_UTILS_H
#define ARNOLD_UTILS_H

#pragma once

#include <algorithm>

namespace Utils
{
    namespace Geometry
    {
        struct Vector2D
        {
            float x;
            float y;
        };

        Vector2D normalise(Vector2D coordinates);

        Vector2D getUnitVector(Vector2D origin, Vector2D destination);

        bool isColliding(const Vector2D &aCords, const Vector2D &aDim, const Vector2D &bCords, Vector2D bDim);
    }
}

#endif // ARNOLD_UTILS_H
