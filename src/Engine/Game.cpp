#include <Game.hpp>
#include <Constants.hpp>

bool Game::init(const char *windowTitle,
                const int xPos, const int yPos,
                const int width, const int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Failed to init SDL!\n");
        return false;
    }

    window = SDL_CreateWindow(
        windowTitle,
        xPos, yPos,
        width, height,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    isRunning = true;
    return true;
}

void Game::handleEvents()
{
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
        if (sdlEvent.type == SDL_QUIT)
        {
            isRunning = false;
            return;
        }
        // Retrieve the player object from the entities list and handle the user's player input
        for (const auto &entity : entities)
        {
            if (auto *player = dynamic_cast<Player *>(entity.get()))
            {
                player->handleEvents(sdlEvent);
                break;
            }
        }
    }
}

void Game::update()
{
    const int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - lastFrameTime);
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
        SDL_Delay(timeToWait);

    const double deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0;
    lastFrameTime = SDL_GetTicks();

    // Remove entities that have been marked for deletion
    entities.erase(
        std::remove_if(
            entities.begin(), entities.end(),
            [](const std::unique_ptr<Entity> &entity)
            {
                return entity->isMarkedForRemoval;
            }),
        entities.end());

    for (const auto &entity : entities)
        entity->update(deltaTime);
}

void Game::render()
{
    SDL_RenderClear(renderer);

    for (const auto &entity : entities)
        entity->render(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Game::clean() const
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Game cleaned\n");
}

const std::vector<std::unique_ptr<Entity>> &Game::getEntities() const
{
    return entities;
}

Player *Game::getPlayer() const
{
    for (const auto &entity : entities)
    {
        if (auto *pPlayer = dynamic_cast<Player *>(entity.get()))
        {
            return pPlayer;
        }
    }
    return nullptr;
}

Game::Game() = default;
