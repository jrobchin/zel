#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>

const std::string WINDOW_NAME = "Zel";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Window {
private:
    /// Initialize SDL and window
    bool _init(std::string windowName, int screenWidth, int screenHeight);

    /// Close window and free memory
    void _close();
    
    SDL_Window* _window;
    SDL_Renderer* _renderer;

public:
    Window(std::string windowName=WINDOW_NAME, int screenWidth=SCREEN_WIDTH, int screenHeight=SCREEN_HEIGHT);
    ~Window();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
};

#endif