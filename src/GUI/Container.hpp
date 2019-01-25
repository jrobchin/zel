#ifndef GUI_CONTAINER_HPP
#define GUI_CONTAINER_HPP

#include <vector>
#include <SDL2/SDL.h>

#include "Math.hpp"
#include "Component.hpp"

/*
 * Container that holds other components. 
 */
class Container: public Component {
public:
    Container(Point<int> origin=Point<int>(0, 0), int width=0, int height=0, int margin=0);
    Container(Rectangle<int> rect, int margin=0);

    /// Used to add child components to the container
    void addChild(Component* component);

    /// Handle inputs for the container and children
    void handleInputs();

    /// Render container and children
    void render();

    SDL_Rect* getRect() {
        return &_rect.sdl_rect;
    }
private:
    /// Margin between contained components
    int _margin;

    /// Dimensions of container
    Rectangle<int> _rect;

    /// Container children
    std::vector<Component*> _children;
};


#endif