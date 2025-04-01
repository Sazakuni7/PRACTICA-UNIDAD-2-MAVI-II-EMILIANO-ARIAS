#ifndef BALL_H
#define BALL_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(b2World& world, sf::Vector2f position, sf::Vector2f direction);
    void update();
    void draw(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::CircleShape shape;
};

#endif