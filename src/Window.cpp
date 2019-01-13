#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Log.hpp"

#include "Window.hpp"

Window* Window::_instance = nullptr;

Window::Window(std::string windowName, int screenWidth, int screenHeight) {
    window = NULL;
    renderer = NULL;
    
    _init(windowName, screenWidth, screenHeight);
}

Window::~Window() {
    _close();
}

Window* Window::Instance() {
    if (!_instance)
        _instance = new Window();
    return _instance;
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
        window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                  screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            Log::error("SDL window creation failed.");
            Log::error(SDL_GetError());
            success = false;

        } else {
            // Get window surface
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL) {
                Log::error("SDL renderer creation failed.");
                Log::error(SDL_GetError());
                success = false;

            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void Window::getSize(int* width, int* height) {
    SDL_GetWindowSize(this->window, width, height);
}

SDL_Color Window::createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_Color color = {r, g, b, a};
    return color;
}

SDL_Color Window::createColor(std::string hex) {

    if (hex.compare(0, 1, "#") == 0) {
        hex.erase(0, 1);
    }
    
    uint8_t r, g, b, a(255);
    
    long int longHex = (int) std::strtol(hex.c_str(), NULL, 16);

    r = (longHex >> 16) & 255;
    g = (longHex >> 8) & 255;
    b = longHex & 255;

    SDL_Color color = {r, g, b, a};

    return color;
}