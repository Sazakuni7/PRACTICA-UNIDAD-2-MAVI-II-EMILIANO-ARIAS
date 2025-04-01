#ifndef BOX_H
#define BOX_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Box {
public:
    Box(b2World& world, float x, float y);
    void move(float velocityY);
    void update();
    void draw(sf::RenderWindow& window);
    void stop();
    void rotateTurret(sf::Vector2f mousePosition);
   // void setNewRotation(float angle);
    sf::Vector2f getPosition() const { return shape.getPosition(); }

private:
    b2Body* body;
    sf::RectangleShape shape;
};

#endif