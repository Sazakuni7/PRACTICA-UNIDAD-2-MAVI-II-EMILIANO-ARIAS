#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Block : public sf::Drawable {
public:
    Block(b2World& world);
    void update();

private:
    b2Body* body;
    sf::RectangleShape shape;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif#
