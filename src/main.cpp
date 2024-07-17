#include <SDL2/SDL.h>
#include <random>
#include <iostream>

#include "Game.hpp"
#include "Player.hpp"
#include "Constants.hpp"
#include "Opponent.hpp"
#include "Ball.hpp"

int main()
{
    Game game;

    char *title = "Pong - Score: 0";

    if (!game.init(
            title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        throw std::runtime_error("Failed to initialise SDL");
    }

    game.addEntity<Player>(Player({(WINDOW_WIDTH / 2) - 25, WINDOW_HEIGHT - 50}, &game));
    game.addEntity<Opponent>(Opponent({100, 50}, &game));
    game.addEntity<Ball>(Ball({100, 100}, &game, {10, 10}, 200.0f));

    while (game.getIsRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
