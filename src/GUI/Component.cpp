#include "Component.hpp"
#include "Log.hpp"

/* 
 * Constructors
 */
Component::Component() {
    _init();
}

Component::Component(Point<int> origin, int width, int height) {
    _init();
    _origin = origin;
    _rect = Rectangle<int>(origin, width, height);
}

void Component::_init() {
    _graphics = nullptr;
    _bgTexture = nullptr;
    _graphics = Graphics::Instance();
    _bgColor = _graphics->createColor(0, 0, 0, 0);
}

Component::~Component() {
    // Free background texture
    if (_bgTexture != nullptr)
        SDL_DestroyTexture(_bgTexture);
}

/* 
 * Getters and Setters
 */
Point<int> Component::getOrigin() {
    return _origin;
}

Rectangle<int> Component::getRect() {
    return _rect;
}

SDL_Rect* Component::getSDL_Rect() {
    return &_rect.sdl_rect;
}

void Component::setOrigin(Point<int> origin) {
    _origin = origin;
}

/* Event handling */
void Component::addEventHandler(Event event, std::function<void()> handler, bool force) {
    
    if (!force && _actions.count(event) > 0) {
        Log::warning("Component already has a handler for that event");
        return;
    }
    
    _actions[event] = handler;
}

void Component::fireEventHandler(Event event) {
    if (_actions.count(event) < 1) {
        Log::warning("Component does not have a handler for event.");
        return;
    }

    _actions[event]();
}

/* 
 * Property setters
 */
void Component::setBackgroundColor(SDL_Color color) {
    _bgColor = color;
}

void Component::setBackgroundColor(std::string hex) {
    _bgColor = _graphics->createColor(hex);
}

void Component::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    _bgColor = _graphics->createColor(r, g, b, a);
}

void Component::setBackgroundTexture(SDL_Texture* texture) {
    _bgTexture = texture;
}