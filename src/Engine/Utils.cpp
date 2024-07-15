#include <Utils.hpp>

using namespace Utils::Geometry;

Vector2D Utils::Geometry::normalise(Vector2D coordinates)
{
    Vector2D normalisedCoordinates = coordinates;
    double const vecMagnitude = sqrt(pow(coordinates.x, 2) + pow(coordinates.y, 2));
    if (vecMagnitude > 0)
    {
        normalisedCoordinates.x /= static_cast<float>(vecMagnitude);
        normalisedCoordinates.y /= static_cast<float>(vecMagnitude);
    }
    return normalisedCoordinates;
}

Vector2D Utils::Geometry::getUnitVector(Vector2D origin, Vector2D destination)
{
    float directionX = destination.x - origin.x;
    float directionY = destination.y - origin.y;
    auto const distance = static_cast<float>(sqrt(pow(directionX, 2) + pow(directionY, 2)));

    directionX /= distance;
    directionY /= distance;

    return {directionX, directionY};
}

bool Utils::Geometry::isColliding(const Vector2D &aCords, const Vector2D &aDim, const Vector2D &bCords, Vector2D bDim)
{
    return std::max(aCords.x, bCords.x) < std::min(aCords.x + aDim.x, bCords.x + bDim.x) &&
           std::max(aCords.y, bCords.y) < std::min(aCords.y + aDim.y, bCords.y + bDim.y);
}
