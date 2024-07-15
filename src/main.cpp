#include <SDL2/SDL.h>
#include <random>
#include <Game.hpp>
#include <Constants.hpp>
#include <Player.hpp>
#include <iostream>

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

    game.addEntity<Player>(Player({200, 400}, &game));

    while (game.getIsRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
