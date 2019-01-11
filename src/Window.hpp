#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>

const std::string WINDOW_NAME = "Zel";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Window {
public:
    static Window* Instance();

    SDL_Window* window;
    SDL_Renderer* renderer;

    void getSize(int* width, int* height);
private:
    /// Singleton instance
    static Window* _instance;
    Window(std::string windowName=WINDOW_NAME, int screenWidth=SCREEN_WIDTH, int screenHeight=SCREEN_HEIGHT);
    ~Window();

    /// Initialize SDL and window
    bool _init(std::string windowName, int screenWidth, int screenHeight);

    /// Close window and free memory
    void _close();
};

#endif