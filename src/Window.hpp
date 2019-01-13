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

    /// Create an SDL_Color
    SDL_Color createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    SDL_Color createColor(std::string hex);
private:
    /// Singletons constructor and destructor are private
    Window(std::string windowName=WINDOW_NAME, int screenWidth=SCREEN_WIDTH, int screenHeight=SCREEN_HEIGHT);
    ~Window();
    
    /// Singleton instance
    static Window* _instance;

    /// Initialize SDL and window
    bool _init(std::string windowName, int screenWidth, int screenHeight);

    /// Close window and free memory
    void _close();
};

#endif