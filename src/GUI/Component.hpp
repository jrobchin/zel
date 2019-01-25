#ifndef GUI_COMPONENT_HPP
#define GUI_COMPONENT_HPP

#include <map>
#include <vector>
#include <functional>

#include "Graphics.hpp"
#include "Math.hpp"

enum class Event {
    CLICK
};

/* 
 * The origin is at the top left.
 * 
 * Coordinates start at top-left. Negative coordinates can be used to start from bottom-right.
 */
class Component {
public:
    Component();
    Component(Point<int> origin, int width, int height);
    ~Component();

    /// Get top-left origin
    Point<int> getOrigin();

    /// Get rectangle for component shape
    Rectangle<int> getRect();

    /// Set the top-left origin
    void setOrigin(Point<int> origin);

    /// Set background color with SDL_Color
    void setBackgroundColor(SDL_Color color);
    /// Set background color with hex string
    void setBackgroundColor(std::string hex);
    /// Set background color with r, g, b, a
    void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    /// Set background texture with SDL_Texture
    void setBackgroundTexture(SDL_Texture* texture);

    /// Add event handler. Handlers must have a void return type and not accept
    /// parameters. Set force=true to replace handlers.
    void addEventHandler(Event event, std::function<void()> handler, bool force=false);
    void fireEventHandler(Event event);

    // Functions must be implemented by child classes
    virtual void handleInputs() = 0;
    virtual void render() = 0;
protected:
    // Every component to be rendered will need a background or texture
    SDL_Color _bgColor;
    SDL_Texture* _bgTexture;

    // Reference to graphics
    Graphics* _graphics;
private:
    // Initialize the component
    void _init();

    // Origin of the component is top-left
    Point<int> _origin;

    // Rectangle containing component
    Rectangle<int> _rect;    

    // For event handling we store a map of events => handler
    std::map<Event, std::function<void()>> _actions;
};

#endif