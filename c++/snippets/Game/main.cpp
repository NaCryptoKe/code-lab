#include <SDL2/SDL.h>
#include <format>
#include <iostream>
#include <memory>

void initialize_sdl();
void close_sdl();

class Game {
public:
    Game();
    void init();
    void run();

    static constexpr int width{800};
    static constexpr int height{600};

private:
    const std::string title;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
};

Game::Game()
    : title{"SDL Window"},
      window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer} {}

void Game::init() {
    window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));

    if (!window) {
        throw std::runtime_error(std::format("Window creation failed: {}", SDL_GetError()));
    }

    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

    if (!renderer) {
        throw std::runtime_error(std::format("Renderer creation failed: {}", SDL_GetError()));
    }
}

void Game::run() {
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer.get(), 20, 20, 20, 255); // dark grey
        SDL_RenderClear(renderer.get());

        // Example render (draw red square)
        SDL_Rect rect{width / 4, height / 4, width / 2, height / 2};
        SDL_SetRenderDrawColor(renderer.get(), 255, 0, 0, 255);
        SDL_RenderFillRect(renderer.get(), &rect);

        // Present on screen
        SDL_RenderPresent(renderer.get());
    }
}

void initialize_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(std::format("SDL Init failed: {}", SDL_GetError()));
    }
    std::cout << "SDL Initialized\n";
}

void close_sdl() {
    SDL_Quit();
    std::cout << "SDL Closed\n";
}

int main() {
    int exit_val = EXIT_SUCCESS;

    try {
        initialize_sdl();
        Game game;
        game.init();
        game.run();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit_val = EXIT_FAILURE;
    }

    close_sdl();
    return exit_val;
}
