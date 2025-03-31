#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class Ground : public sf::Drawable {
public:
    Ground(b2World& world);

private:
    b2Body* body;
    sf::RectangleShape shape;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif