#include <SDL2/SDL.h>
#include <random>
#include <iostream>

#include "Game.hpp"
#include "Player.hpp"
#include "Constants.hpp"

int main()
{
    Game game;

    if (!game.init(
            "Pong",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        throw std::runtime_error("Failed to initialise SDL");
    }

    game.addEntity<Player>(Player({(WINDOW_WIDTH / 2) - 25, WINDOW_HEIGHT - 50}, &game));

    while (game.getIsRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
