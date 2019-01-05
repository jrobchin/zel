#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Log.hpp"

#include "Window.hpp"

Window::Window(std::string windowName, int screenWidth, int screenHeight) {
    _window = NULL;
    _renderer = NULL;
    
    _init(windowName, screenWidth, screenHeight);
}

Window::~Window() {
    _close();
}

bool Window::_init(std::string windowName, int screenWidth, int screenHeight) {
    
    Log::verbose("Initializing SDL2 and window.");

    bool success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Log::error("SDL initialization failed.");
        Log::error(SDL_GetError());
        success = false;
    } else {
        // Create window
        _window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                  screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (_window == NULL) {
            Log::error("SDL window creation failed.");
            Log::error(SDL_GetError());
            success = false;

        } else {
            // Get window surface
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if (_renderer == NULL) {
                Log::error("SDL renderer creation failed.");
                Log::error(SDL_GetError());
                success = false;

            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

                // Initialize SDL images
                int imgFlags = IMG_INIT_PNG;
                if (!IMG_Init(imgFlags) & imgFlags) {
                    Log::error("SDL_image initialization failed.");
                    Log::error(SDL_GetError());
                    success = false;
                }

            }

        }
    }

    return success;
}

void Window::_close() {
    Log::verbose("Closing SDL2 and window.");

    //Destroy window    
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    _window = NULL;
    _renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Window* Window::getWindow() {
    return _window;
}

SDL_Renderer* Window::getRenderer() {
    return _renderer;
}