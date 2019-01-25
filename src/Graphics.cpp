#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Log.hpp"

#include "Graphics.hpp"

Graphics* Graphics::_instance = nullptr;

Graphics::Graphics(std::string windowName, int screenWidth, int screenHeight) {
    window = NULL;
    renderer = NULL;
    
    _init(windowName, screenWidth, screenHeight);
}

Graphics::~Graphics() {
    _close();
}

Graphics* Graphics::Instance() {
    if (!_instance)
        _instance = new Graphics();
    return _instance;
}

bool Graphics::_init(std::string windowName, int screenWidth, int screenHeight) {
    
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
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer == NULL) {
                Log::error("SDL renderer creation failed.");
                Log::error(SDL_GetError());
                success = false;

            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);

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

void Graphics::_close() {
    //Destroy window    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void Graphics::getWindowSize(int* width, int* height) {
    SDL_GetWindowSize(this->window, width, height);
}

/* 
    Draw functions
 */
void Graphics::clearRender() {
    SDL_RenderClear(renderer);
}

void Graphics::presentRender() {
    SDL_RenderPresent(renderer);
}

void Graphics::setDrawColor(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Graphics::drawTexture(SDL_Texture* texture, SDL_Rect* clipRect) {
    SDL_RenderCopy(renderer, texture, clipRect, NULL);
}

void Graphics::setViewport(SDL_Rect* viewport) {
    SDL_RenderSetViewport(renderer, viewport);
}

void Graphics::resetViewport() {
    // Passing NULL resets the viewport to fullscreen
    SDL_RenderSetViewport(renderer, NULL);
}

/* 
    Creators
 */
SDL_Color Graphics::createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_Color color = {r, g, b, a};
    return color;
}

SDL_Color Graphics::createColor(std::string hex) {

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

SDL_Texture* Graphics::createTexture(std::string fpath) {
    SDL_Texture* newTexture;

    // Create surface from image
    SDL_Surface* loadedSurface = IMG_Load(fpath.c_str());
    if (loadedSurface == nullptr) {
        // Image load failed
        std::string error_msg = "Unable to load image at " + fpath + " error: " + IMG_GetError();
        Log::error(error_msg);
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            // Texture creation failed
            std::string error_msg = "Unable to create texture of " + fpath + ". error: " + IMG_GetError();
            Log::error(error_msg);
        }
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}