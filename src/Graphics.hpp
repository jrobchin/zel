#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>

const std::string WINDOW_NAME = "Zel";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics {
public:
    static Graphics* Instance();

    SDL_Window* window;
    SDL_Renderer* renderer;

    void getWindowSize(int* width, int* height);

    /// Clear render
    void clearRender();
    void presentRender();

    /* Draw functions */
    /// Set draw color on render clear
    void setDrawColor(SDL_Color color);
    /// Set window background color
    void setBackgroundColor(SDL_Color color);
    /// Draw a texture to the renderer. Optionally pass a rectangle to clip the texture.
    void drawTexture(SDL_Texture* texture, SDL_Rect* clipRect=NULL);
    /// Set the viewport for next rendering. Pass NULL to reset the viewport.
    void setViewport(SDL_Rect* viewport);
    /// Reset viewport to fullscreen
    void resetViewport();

    /// Create an SDL_Color
    SDL_Color createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    SDL_Color createColor(std::string hex);

    /// Create SDL_Texture
    SDL_Texture* createTexture(std::string fpath);
private:
    /// Singletons constructor and destructor are private
    Graphics(std::string windowName=WINDOW_NAME, int screenWidth=SCREEN_WIDTH, int screenHeight=SCREEN_HEIGHT);
    ~Graphics();
    
    /// Singleton instance
    static Graphics* _instance;

    /// Initialize SDL and graphics
    bool _init(std::string windowName, int screenWidth, int screenHeight);

    /// Close graphics and free memory
    void _close();

    /// Default bg color drawn on render clear
    struct {
        uint8_t r = 0, g = 0, b = 0, a = 255;
    } _bgColor;
};

#endif