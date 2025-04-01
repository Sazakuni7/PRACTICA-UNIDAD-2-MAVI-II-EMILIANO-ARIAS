#ifndef BOX_H
#define BOX_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Box {
public:
    Box(b2World& world, float x, float y);
    void applyForce(float force);
    void update();
    void draw(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::RectangleShape shape;
};

#endif