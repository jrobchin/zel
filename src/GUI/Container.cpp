#include "Container.hpp"

Container::Container(Point<int> origin, int width, int height, int margin) :
    Component(origin, width, height),
    _margin(margin)
{
    _rect = Rectangle<int>(origin, width, height);
}

Container::Container(Rectangle<int> rect, int margin) :
    Component(rect.topLeft(), rect.width(), rect.height()),
    _margin(margin)
{
    _rect = rect;
}

void Container::addChild(Component* component) {
    _children.push_back(component);
}

void Container::handleInputs() {
    for (Component* child : _children) {
        child->handleInputs();
    }
}

void Container::render() {
    // Set viewport for container
    _graphics->setViewport(&_rect.sdl_rect);

    // Render the container's background texture
    _graphics->drawTexture(_bgTexture);

    // Render child components
    for (Component* child : _children) {
        child->render();
    }
}